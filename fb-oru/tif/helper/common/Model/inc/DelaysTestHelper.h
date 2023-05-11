/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      DelaysTestHelper.h
 * \brief     Test helper for common
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __DELAYSTESTHELPER__H_
#define __DELAYSTESTHELPER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "IRtiMsgParser.h"
#include "DataVariant.h"

// Add any specific includes here %%-->
#include "IDelaysMgr.h"
#include "ICpriDelays.h"
// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class DelaysTestHelper
// Add any extra inheritance %%-->

// <--%%
{
public:

	// Add any class settings %%-->

	// <--%%

	// singleton
	static std::shared_ptr<DelaysTestHelper> getInstance() ;


	DelaysTestHelper();

    virtual ~DelaysTestHelper();

	/**
	 * Called with:
	 *   UINT carrier
	 *   UINT{1..${NUM_TX_PORTS}} tx
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT delay (ns)
	 *
	 */
	void getAdjDelayDown( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT carrier
	 *   UINT{1..${NUM_RX_PORTS}} rx
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT delay (ns)
	 *
	 */
	void getAdjDelayUp( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT dlLimit (ns)
	 *   UINT dlStep (ns)
	 *   UINT ulLimit (ns)
	 *   UINT ulStep (ns)
	 *
	 */
	void getAdjLimits( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{1..${NUM_TX_PORTS}} tx
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT delay (ns)
	 *
	 */
	void getExtDelayDown( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{1..${NUM_RX_PORTS}} rx
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT delay (ns)
	 *
	 */
	void getExtDelayUp( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT carrier
	 *   UINT{1..${NUM_TX_PORTS}} tx
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   UINT delay (BF)
	 *
	 */
	void getFrameOffsetDown( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT carrier
	 *   UINT{1..${NUM_TX_PORTS}} tx
	 *   UINT delay (ns)
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setAdjDelayDown( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT carrier
	 *   UINT{1..${NUM_RX_PORTS}} rx
	 *   UINT delay (ns)
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setAdjDelayUp( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{1..${NUM_TX_PORTS}} tx
	 *   UINT delay (ns)
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setExtDelayDown( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT{1..${NUM_RX_PORTS}} rx
	 *   UINT delay (ns)
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setExtDelayUp( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   UINT carrier
	 *   UINT{1..${NUM_TX_PORTS}} tx
	 *   UINT delay (BF)
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void setFrameOffsetDown( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void show( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );






// Add any extra methods %%-->
private:
	std::shared_ptr<IDelaysMgr> mDelayInterface ;

// <--%%

};



// Add any Mplane namespace code here %%-->

// <--%%


} // Mplane

// Add any global namespace code here %%-->

// <--%%


#endif /* __DELAYSTESTHELPER__H_*/