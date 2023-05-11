#ifndef _VRH_IFPGAMGR_H_
#define _VRH_IFPGAMGR_H_

/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      IFpgaMgr.h
 * \brief     Virtual interface for managing fpga register regions
 *
 *
 * \details   Virtual interface for managing fpga register regions
 *
 * ** AUTO-GENERATED - DO NOT EDIT THIS FILE **
 *
 */

#include <memory>

#include "GlobalTypeDefs.h"
#include "IFpgaKernel.h"

@@#include "fpga/@name@.h"@@

namespace Mplane
{

/*! \brief  Generic FPGA Interface
 *
 *  A virtual interface base class defining a functional interface that must be
 *  adopted by any implementation of a generic FPGA interface.
 *
 *  This virtual interface allows an FPGA to expose its functionality, allowing
 *  developers to logically group the functionality of one or more FPGAs
 *  into an interface class.
 *
 */
class IFpgaMgr
{
public:
    virtual ~IFpgaMgr() { };


    /** \brief  Get the singleton instance
     *
     *  Used to get a reference to the single instance of the generic FPGA
     *  object. This must be implemented using the singleton pattern by the
     *  specific radio implementation.
     *
     *  Must be define in: hardware/<BOARD>/radio/src/<Board>Fpga.cpp
     *
     *  Test mock defined in: vrh/test/src/TestIFpga.cpp
     *
     *
     */
    static std::shared_ptr<IFpgaMgr> singleton(void);

    /*! \brief  Get fpga kernel
     *
     *  Get the fpga kernel driver
     *
     *  \return pointer to fpga kernel
     */
    static std::shared_ptr<IFpgaKernel> kernel() ;


    // Register access
@@    static std::shared_ptr<@name@> get@name@() ;@@

    /*! \brief  The initialise method
     *
     *  Method called during system startup, post FPGA image load, to fully
     *  initialise the device and to override any initial settings with
     *  board-specific ones.
     *
     *  \return state of RT_OK if successful, RT_other if not.
     */
    virtual ReturnType::State initialise(void) =0;

#if 0
    /*! \brief  Read an fpga 16-bit register
     *
     *  Method used to return the FPGA register value at the specified offset.
     *
     *  \return  FpgaVal FPGA register contents
     */
    virtual UINT16 readRegister(unsigned offset) =0;

    /*! \brief  Write an fpga 16-bit register
     *
     *  Method used to write an FPGA register value at the specified offset.
     *
     */
    virtual void writeRegister(unsigned offset, UINT16 value) =0;

    /*! \brief  Modify an fpga 16-bit register
     *
     *  Method used to write an FPGA register value at the specified offset.
     *
     */
    virtual void modifyRegister(unsigned offset, UINT16 value, UINT16 mask) =0;

    /*! \brief  Read an fpga 32-bit register
     *
     *  Method used to return the FPGA register value at the specified offset.
     *
     *  \return  FpgaVal FPGA register contents
     */
    virtual UINT32 readRegister32(unsigned offset) =0;

    /*! \brief  Write an fpga 32-bit register
     *
     *  Method used to write an FPGA register value at the specified offset.
     *
     */
    virtual void writeRegister32(unsigned offset, UINT32 value) =0;

    /*! \brief  Modify an fpga 32-bit register
     *
     *  Method used to write an FPGA register value at the specified offset.
     *
     */
    virtual void modifyRegister32(unsigned offset, UINT32 value, UINT32 mask) =0;
#endif

    // Register access
@@	virtual void set@name@(std::shared_ptr<@name@> regs) =0 ;@@

protected:
@@	virtual std::shared_ptr<@name@> _get@name@() =0 ;@@
    virtual std::shared_ptr<IFpgaKernel> _kernel() =0 ;


protected:
    /*! \brief  Default constructor
     *
     *  Ensure we can only be constructed via an implementing class.
     */
    IFpgaMgr() {};

};



} /* namespace Mplane */

#endif // _VRH_IFPGAMGR_H_