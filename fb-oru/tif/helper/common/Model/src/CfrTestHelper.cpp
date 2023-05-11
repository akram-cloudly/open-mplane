/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      CfrTestHelper.cpp
 * \brief     Test helper for common
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run)
 *
 */


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include "RtiKeyword.h"
#include "CfrTestHelper.h"

// Add any specific includes here %%-->
#include "ITifIoctl.h"
#include "ICarrierModel.h"
// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%



//=============================================================================================================
// SINGLETON
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<CfrTestHelper> CfrTestHelper::getInstance()
{
	static std::shared_ptr<CfrTestHelper> instance(std::make_shared<CfrTestHelper>()) ;
	return instance ;
}

//=============================================================================================================
// PUBLIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
CfrTestHelper::CfrTestHelper()
// Insert additional inheritance constructors here : %%-->

// <--%%
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
CfrTestHelper::~CfrTestHelper()
{
	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CfrTestHelper::set( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * [BOOL(OFF:ON) enable]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
	std::shared_ptr<ITifIoctl> cfrWorker( getCfrWorker() );
	if (!cfrWorker)
		return ;

	cfrWorker->executeCommand("set", callList, returnList) ;
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CfrTestHelper::setThresholds( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} index
	// * FLOAT[] threshold (dB)
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
	std::shared_ptr<ITifIoctl> cfrWorker( getCfrWorker() );
	if (!cfrWorker)
		return ;

	if (!cfrWorker->executeCommand("setThresholds", callList, returnList))
	{
		returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );
		returnList->find(RtiKeyword::MESSAGE_VAR)->set("Unable to set thresholds") ;
	}

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CfrTestHelper::show( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
	std::shared_ptr<ITifIoctl> cfrWorker( getCfrWorker() );
	if (!cfrWorker)
		return ;

	cfrWorker->executeCommand("show", callList, returnList) ;
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CfrTestHelper::showThresholds( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_TX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT[] threshold (dB)
	//

	// Insert your code here : %%-->
	std::shared_ptr<ITifIoctl> cfrWorker( getCfrWorker() );
	if (!cfrWorker)
		return ;

	cfrWorker->executeCommand("showThresholds", callList, returnList) ;

	// <--%%
}










// Add any statics, private methods etc here %%-->

//=============================================================================================================
// PRIVATE
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<ITifIoctl> Mplane::CfrTestHelper::getCfrWorker() const
{
	std::shared_ptr<ICarrierModel> carrierModel(ICarrierModel::getInstance());
	if( !carrierModel )
	    return nullptr;
	std::shared_ptr<ITifIoctl> modelTifioctl( std::dynamic_pointer_cast<ITifIoctl>(carrierModel));
	if (!modelTifioctl)
		return nullptr ;
	std::shared_ptr<ITifIoctl> cfrWorker( modelTifioctl->getObject("CfrWorker") );
	return cfrWorker ;
}
// <--%%