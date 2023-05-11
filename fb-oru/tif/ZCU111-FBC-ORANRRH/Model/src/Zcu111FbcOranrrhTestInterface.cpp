/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      Zcu111FbcOranrrhTestInterface.cpp
 * \brief     Test interface for ZCU111-FBC-ORANRRH
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions.
 *
 */


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include "Zcu111FbcOranrrhTestInterface.h"

#include "Zcu111FbcOranrrhAgcTestHandler.h"
#include "Zcu111FbcOranrrhCarrierTestHandler.h"
#include "Zcu111FbcOranrrhCarrierHwTestHandler.h"
#include "Zcu111FbcOranrrhDot1agdMonTestHandler.h"
#include "Zcu111FbcOranrrhEmbeddedTestHandler.h"
#include "Zcu111FbcOranrrhEqualiserTestHandler.h"
#include "Zcu111FbcOranrrhFibreTestHandler.h"
#include "Zcu111FbcOranrrhFpgaTestHandler.h"
#include "Zcu111FbcOranrrhFtpTestHandler.h"
#include "Zcu111FbcOranrrhGpioTestHandler.h"
#include "Zcu111FbcOranrrhHeartbeatTestHandler.h"
#include "Zcu111FbcOranrrhI2cTestHandler.h"
#include "Zcu111FbcOranrrhIpTestHandler.h"
#include "Zcu111FbcOranrrhIpListTestHandler.h"
#include "Zcu111FbcOranrrhNetopeerMonTestHandler.h"
#include "Zcu111FbcOranrrhOranFpgaTestHandler.h"
#include "Zcu111FbcOranrrhRadioStateTestHandler.h"
#include "Zcu111FbcOranrrhRegDevicesTestHandler.h"
#include "Zcu111FbcOranrrhRxPortTestHandler.h"
#include "Zcu111FbcOranrrhSrxPortTestHandler.h"
#include "Zcu111FbcOranrrhSystemTestHandler.h"
#include "Zcu111FbcOranrrhSystemConfigTestHandler.h"
#include "Zcu111FbcOranrrhTxPortTestHandler.h"
#include "Zcu111FbcOranrrhYangConfigTestHandler.h"
#include "Zcu111FbcOranrrhYangManagerTestHandler.h"
#include "Zcu111FbcOranrrhYangTestTestHandler.h"


using namespace Mplane ;

//=============================================================================================================
// PUBLIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
Zcu111FbcOranrrhTestInterface::Zcu111FbcOranrrhTestInterface()
{
	Zcu111FbcOranrrhAgcTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhCarrierTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhCarrierHwTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhDot1agdMonTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhEmbeddedTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhEqualiserTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhFibreTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhFpgaTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhFtpTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhGpioTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhHeartbeatTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhI2cTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhIpTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhIpListTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhNetopeerMonTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhOranFpgaTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhRadioStateTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhRegDevicesTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhRxPortTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhSrxPortTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhSystemTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhSystemConfigTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhTxPortTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhYangConfigTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhYangManagerTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;

	Zcu111FbcOranrrhYangTestTestHandler::registerMethods(/* IRtiMsgParser */ *this, /* IRtiSettings */ *this) ;


}

//-------------------------------------------------------------------------------------------------------------
Zcu111FbcOranrrhTestInterface::~Zcu111FbcOranrrhTestInterface()
{
}