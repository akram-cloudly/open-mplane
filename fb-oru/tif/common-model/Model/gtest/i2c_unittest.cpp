/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      i2c_unittest.cpp
 * \brief
 *
 *
 * \details
 *
 */


//=============================================================================================================
// INCLUDE
//=============================================================================================================

#include "gtest/gtest.h"

#include <regex.h>

#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

#include "stringfunc.hpp"
#include "model_fixture.h"

using namespace Mplane ;

class I2cModelTests : public ModelTests
{
};

//===================================================================================================================
/*
 * Unit tests
 */



//-------------------------------------------------------------------------------------------------------------------
TEST_F(I2cModelTests, commands)
{
	// Test parameters
	std::string result ;

    result = runCmdOk("su WangLi5H");
    result = runCmdOk("cd /i2c");
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

	/* ***** Lock Tests ***** */
	result = runCmdOk("lock");
	EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdError("lock");
    EXPECT_TRUE( result.find("I2C Bus already locked : ERROR_OPERATION_FAILED" ) != std::string::npos );

    /* ***** Unlock Tests ***** */
    result = runCmdOk("unlock");
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdError("unlock");
    EXPECT_TRUE( result.find("I2C Bus already unlocked : ERROR_OPERATION_FAILED") != std::string::npos );

    /* ***** Read when unlocked Tests ***** */
    result = runCmdError("read 0x71        0x01           0x01 "); // 1 byte
    EXPECT_TRUE( result.find("I2C Bus not locked. Please lock the bus using - i2c.lock : ERROR_OPERATION_FAILED") != std::string::npos );

    /* ***** Write when unlocked Tests ***** */
    result = runCmdError("write 0x71        0x00");                // Test only 1 data byte
    EXPECT_TRUE( result.find("I2C Bus not locked. Please lock the bus using - i2c.lock : ERROR_OPERATION_FAILED") != std::string::npos );

	/* ***** Lets lock and go! Read Tests ***** */
    result = runCmdOk("lock");
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

	//                         Device Addr Reg Addr       Number of bytes to read
    result = runCmdError("read 0xff        0x00           0x00"); // invalid address
    EXPECT_TRUE( result.find("Unable to set device address. Exceeds maximum of 0x80 : ERROR_OUT_OF_RANGE") != std::string::npos );

	result = runCmdError("read 0x71        0x00           0x00 "); // invalid number of bytes to read
    EXPECT_TRUE( result.find("Unable to set number of bytes to read. Value has to be greater than 0x00 and not exceed 0xff : ERROR_OUT_OF_RANGE") != std::string::npos );

    result = runCmdError("read 0x71        0x00           0x100 "); // invalid number of bytes to read
    EXPECT_TRUE( result.find("Unable to set number of bytes to read. Value has to be greater than 0x00 and not exceed 0xff : ERROR_OUT_OF_RANGE") != std::string::npos );

    result = runCmdOk("read    0x71        0x01           0x01 "); // 1 byte
    EXPECT_TRUE( result.find("Status=OK , =0x0") != std::string::npos );

    result = runCmdOk("read    0x71        0x08           0x08 "); // 8 bytes
    EXPECT_TRUE( result.find("Status=OK , =0x0 , =0x1 , =0x2 , =0x3 , =0x4 , =0x5 , =0x6 , =0x7") != std::string::npos );

    result = runCmdOk("read    0x71        0x08           0x0f "); // 16 bytes
    EXPECT_TRUE( result.find("Status=OK , =0x0 , =0x1 , =0x2 , =0x3 , =0x4 , =0x5 , =0x6 , =0x7 , =0x8 , =0x9 , =0xA , =0xB , =0xC , =0xD , =0xE") != std::string::npos );

    result = runCmdOk("read    0x71        0x08           0xff "); // 255 bytes
    EXPECT_TRUE( result.find("Status=OK , =0x0 , =0x1 , =0x2 , =0x3 , =0x4 , =0x5 , =0x6 , =0x7 , =0x8 , =0x9 , =0xA , =0xB , =0xC , =0xD , =0xE , =0xF , =0x1 , =0x11 , =0x12 , =0x13 , =0x14 , =0x15 , =0x16 , =0x17 , =0x18 , =0x19 , =0x1A , =0x1B , =0x1C , =0x1D , =0x1E , =0x1F , =0x2 , =0x21 , =0x22 , =0x23 , =0x24 , =0x25 , =0x26 , =0x27 , =0x28 , =0x29 , =0x2A , =0x2B , =0x2C , =0x2D , =0x2E , =0x2F , =0x3 , =0x31 , =0x32 , =0x33 , =0x34 , =0x35 , =0x36 , =0x37 , =0x38 , =0x39 , =0x3A , =0x3B , =0x3C , =0x3D , =0x3E , =0x3F , =0x4 , =0x41 , =0x42 , =0x43 , =0x44 , =0x45 , =0x46 , =0x47 , =0x48 , =0x49 , =0x4A , =0x4B , =0x4C , =0x4D , =0x4E , =0x4F , =0x5 , =0x51 , =0x52 , =0x53 , =0x54 , =0x55 , =0x56 , =0x57 , =0x58 , =0x59 , =0x5A , =0x5B , =0x5C , =0x5D , =0x5E , =0x5F , =0x6 , =0x61 , =0x62 , =0x63 , =0x64 , =0x65 , =0x66 , =0x67 , =0x68 , =0x69 , =0x6A , =0x6B , =0x6C , =0x6D , =0x6E , =0x6F , =0x7 , =0x71 , =0x72 , =0x73 , =0x74 , =0x75 , =0x76 , =0x77 , =0x78 , =0x79 , =0x7A , =0x7B , =0x7C , =0x7D , =0x7E , =0x7F , =0x8 , =0x81 , =0x82 , =0x83 , =0x84 , =0x85 , =0x86 , =0x87 , =0x88 , =0x89 , =0x8A , =0x8B , =0x8C , =0x8D , =0x8E , =0x8F , =0x9 , =0x91 , =0x92 , =0x93 , =0x94 , =0x95 , =0x96 , =0x97 , =0x98 , =0x99 , =0x9A , =0x9B , =0x9C , =0x9D , =0x9E , =0x9F , =0xA , =0xA1 , =0xA2 , =0xA3 , =0xA4 , =0xA5 , =0xA6 , =0xA7 , =0xA8 , =0xA9 , =0xAA , =0xAB , =0xAC , =0xAD , =0xAE , =0xAF , =0xB , =0xB1 , =0xB2 , =0xB3 , =0xB4 , =0xB5 , =0xB6 , =0xB7 , =0xB8 , =0xB9 , =0xBA , =0xBB , =0xBC , =0xBD , =0xBE , =0xBF , =0xC , =0xC1 , =0xC2 , =0xC3 , =0xC4 , =0xC5 , =0xC6 , =0xC7 , =0xC8 , =0xC9 , =0xCA , =0xCB , =0xCC , =0xCD , =0xCE , =0xCF , =0xD , =0xD1 , =0xD2 , =0xD3 , =0xD4 , =0xD5 , =0xD6 , =0xD7 , =0xD8 , =0xD9 , =0xDA , =0xDB , =0xDC , =0xDD , =0xDE , =0xDF , =0xE , =0xE1 , =0xE2 , =0xE3 , =0xE4 , =0xE5 , =0xE6 , =0xE7 , =0xE8 , =0xE9 , =0xEA , =0xEB , =0xEC , =0xED , =0xEE , =0xEF , =0xF , =0xF1 , =0xF2 , =0xF3 , =0xF4 , =0xF5 , =0xF6 , =0xF7 , =0xF8 , =0xF9 , =0xFA , =0xFB , =0xFC , =0xFD , =0xFE") != std::string::npos );

    result = runCmdError("read 0x72        0x100          0x00"); // invalid register address
    EXPECT_TRUE( result.find("Unable to set number of bytes to read. Value has to be greater than 0x00 and not exceed 0xff : ERROR_OUT_OF_RANGE") != std::string::npos );

    result = runCmdError("read 0x72        0x00"); // invalid number of bytes to read
    EXPECT_TRUE( result.find("Unable to set number of bytes to read. Value has to be greater than 0x00 and not exceed 0xff : ERROR_OUT_OF_RANGE") != std::string::npos );

    result = runCmdOk("read    0x71        0x01 "); // 1 byte
    EXPECT_TRUE( result.find("Status=OK , =0x0") != std::string::npos );

    result = runCmdOk("read    0x71        0x08 "); // 8 bytes
    EXPECT_TRUE( result.find("Status=OK , =0x0 , =0x1 , =0x2 , =0x3 , =0x4 , =0x5 , =0x6 , =0x7") != std::string::npos );

    result = runCmdOk("read    0x71        0x0f "); // 16 bytes
    EXPECT_TRUE( result.find("Status=OK , =0x0 , =0x1 , =0x2 , =0x3 , =0x4 , =0x5 , =0x6 , =0x7 , =0x8 , =0x9 , =0xA , =0xB , =0xC , =0xD , =0xE") != std::string::npos );

    result = runCmdOk("read    0x71        0xff "); // 255 bytes
    EXPECT_TRUE( result.find("Status=OK , =0x0 , =0x1 , =0x2 , =0x3 , =0x4 , =0x5 , =0x6 , =0x7 , =0x8 , =0x9 , =0xA , =0xB , =0xC , =0xD , =0xE , =0xF , =0x1 , =0x11 , =0x12 , =0x13 , =0x14 , =0x15 , =0x16 , =0x17 , =0x18 , =0x19 , =0x1A , =0x1B , =0x1C , =0x1D , =0x1E , =0x1F , =0x2 , =0x21 , =0x22 , =0x23 , =0x24 , =0x25 , =0x26 , =0x27 , =0x28 , =0x29 , =0x2A , =0x2B , =0x2C , =0x2D , =0x2E , =0x2F , =0x3 , =0x31 , =0x32 , =0x33 , =0x34 , =0x35 , =0x36 , =0x37 , =0x38 , =0x39 , =0x3A , =0x3B , =0x3C , =0x3D , =0x3E , =0x3F , =0x4 , =0x41 , =0x42 , =0x43 , =0x44 , =0x45 , =0x46 , =0x47 , =0x48 , =0x49 , =0x4A , =0x4B , =0x4C , =0x4D , =0x4E , =0x4F , =0x5 , =0x51 , =0x52 , =0x53 , =0x54 , =0x55 , =0x56 , =0x57 , =0x58 , =0x59 , =0x5A , =0x5B , =0x5C , =0x5D , =0x5E , =0x5F , =0x6 , =0x61 , =0x62 , =0x63 , =0x64 , =0x65 , =0x66 , =0x67 , =0x68 , =0x69 , =0x6A , =0x6B , =0x6C , =0x6D , =0x6E , =0x6F , =0x7 , =0x71 , =0x72 , =0x73 , =0x74 , =0x75 , =0x76 , =0x77 , =0x78 , =0x79 , =0x7A , =0x7B , =0x7C , =0x7D , =0x7E , =0x7F , =0x8 , =0x81 , =0x82 , =0x83 , =0x84 , =0x85 , =0x86 , =0x87 , =0x88 , =0x89 , =0x8A , =0x8B , =0x8C , =0x8D , =0x8E , =0x8F , =0x9 , =0x91 , =0x92 , =0x93 , =0x94 , =0x95 , =0x96 , =0x97 , =0x98 , =0x99 , =0x9A , =0x9B , =0x9C , =0x9D , =0x9E , =0x9F , =0xA , =0xA1 , =0xA2 , =0xA3 , =0xA4 , =0xA5 , =0xA6 , =0xA7 , =0xA8 , =0xA9 , =0xAA , =0xAB , =0xAC , =0xAD , =0xAE , =0xAF , =0xB , =0xB1 , =0xB2 , =0xB3 , =0xB4 , =0xB5 , =0xB6 , =0xB7 , =0xB8 , =0xB9 , =0xBA , =0xBB , =0xBC , =0xBD , =0xBE , =0xBF , =0xC , =0xC1 , =0xC2 , =0xC3 , =0xC4 , =0xC5 , =0xC6 , =0xC7 , =0xC8 , =0xC9 , =0xCA , =0xCB , =0xCC , =0xCD , =0xCE , =0xCF , =0xD , =0xD1 , =0xD2 , =0xD3 , =0xD4 , =0xD5 , =0xD6 , =0xD7 , =0xD8 , =0xD9 , =0xDA , =0xDB , =0xDC , =0xDD , =0xDE , =0xDF , =0xE , =0xE1 , =0xE2 , =0xE3 , =0xE4 , =0xE5 , =0xE6 , =0xE7 , =0xE8 , =0xE9 , =0xEA , =0xEB , =0xEC , =0xED , =0xEE , =0xEF , =0xF , =0xF1 , =0xF2 , =0xF3 , =0xF4 , =0xF5 , =0xF6 , =0xF7 , =0xF8 , =0xF9 , =0xFA , =0xFB , =0xFC , =0xFD , =0xFE") != std::string::npos );

    // Finally lets unlock
    result = runCmdOk("unlock");
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    /* ***** Lets lock and go! Write Tests ***** */
    result = runCmdOk("lock");
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    //                          Device Addr 1st Data Byte   2nd Data Byte
    result = runCmdError("write 0xff        0x00            0x00"); // invalid address
    EXPECT_TRUE( result.find("Unable to set device address. Exceeds maximum of 0x80 : ERROR_OUT_OF_RANGE") != std::string::npos );

    result = runCmdOk("write    0x71        0x00");                // Test only 1 data byte
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdOk("write    0x71        0x02");                // Test only 1 data byte
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdOk("write    0x71        0xff");                // Test only 1 data byte
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdError("write 0x71        0x100");               // Test only 1 data byte, too big!
    EXPECT_TRUE( result.find("Unable to set first data byte. Value can be no greater than 0xff : ERROR_OUT_OF_RANGE") != std::string::npos );

    result = runCmdOk("write    0x71        0xfe           0x00"); // Test 2 data bytes
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdOk("write    0x71        0xfe           0x01"); // Test 2 data bytes
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdOk("write    0x71        0xfe           0xff"); // Test 2 data bytes
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );

    result = runCmdError("write 0x71        0xfe           0x100");// Test 2 data bytes, 2nd is too big!
    EXPECT_TRUE( result.find("Unable to set second data byte. Value can be omitted or has to be greater than 0x00 and not exceed 0xff : ERROR_OUT_OF_RANGE") != std::string::npos );

    // Finally lets unlock
    result = runCmdOk("unlock");
    EXPECT_TRUE( result.find("Status=OK") != std::string::npos );
}