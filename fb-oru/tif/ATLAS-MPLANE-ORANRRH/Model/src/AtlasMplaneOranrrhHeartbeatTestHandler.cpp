/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      AtlasMplaneOranrrhHeartbeatTestHandler.cpp
 * \brief     Test methods for Atlas-MPLANE-ORANRRH
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run)
 *
 * Add any file header comments here %%-->

 * <--%%
 *
 */


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include "Nodes/RtiDirEntry.h"
#include "Nodes/TestVar.h"
#include "Nodes/TestReadVar.h"
#include "Nodes/TestWriteVar.h"
#include "Nodes/DirClass.h"
#include "RtiKeyword.h"
#include "AtlasMplaneOranrrhHeartbeatTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/heartbeat", "Heartbeat Monitor", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhHeartbeatTestHandler("/heartbeat/getEnable",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],BOOL(OFF:ON) enable",
			"Get the current enable state",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhHeartbeatTestHandler("/heartbeat/getState",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],BOOL(OK:EXPIRED) state",
			"Has timeout timer expired",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhHeartbeatTestHandler("/heartbeat/getTimeout",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],INT timeout (s)",
			"Get the current timeout period",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhHeartbeatTestHandler("/heartbeat/ping",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Keep the heartbeat 'ticking'",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhHeartbeatTestHandler("/heartbeat/setEnable",
			"BOOL(OFF:ON) enable",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Set the enable",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhHeartbeatTestHandler("/heartbeat/setTimeout",
			"INT timeout (s)",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Set the timeout period",
			msgParser, settings))
	);



	msgParser.add( static_cast<RtiDirEntry *>(new TestVar("/heartbeat/enable", "BOOL(OFF:ON)",
			"Heartbeat monitor enable",
			enableGet, enableSet,
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new TestVar("/heartbeat/timeout", "INT",
			"Timeout period",
			timeoutGet, timeoutSet,
			msgParser, settings))
	);



	msgParser.add( static_cast<RtiDirEntry *>(new TestReadVar("/heartbeat/state", "BOOL(OK:EXPIRED)",
			"Has timeout timer expired",
			stateGet,
			msgParser, settings))
	);



}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhHeartbeatTestHandler::AtlasMplaneOranrrhHeartbeatTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(HeartbeatTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhHeartbeatTestHandler::AtlasMplaneOranrrhHeartbeatTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(HeartbeatTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhHeartbeatTestHandler::~AtlasMplaneOranrrhHeartbeatTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool AtlasMplaneOranrrhHeartbeatTestHandler::registerEntry(ITif* tif)
{
	// Convert ITif object into it's expected subclasses
	IRtiMsgParser* msgParser(dynamic_cast<IRtiMsgParser*>(tif)) ;
	IRtiSettings* settings(dynamic_cast<IRtiSettings*>(tif)) ;
	if (!msgParser)
		return false ;
	if (!settings)
		return false ;

	// now call this object's registerMethods() method to do the actual work
	registerMethods(*msgParser, *settings) ;
	return true ;
}


//-------------------------------------------------------------------------------------------------------------
std::string AtlasMplaneOranrrhHeartbeatTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "getEnable")
    {
        getEnable( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getState")
    {
        getState( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getTimeout")
    {
        getTimeout( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "ping")
    {
        ping( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setEnable")
    {
        setEnable( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setTimeout")
    {
        setTimeout( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::getEnable(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * BOOL(OFF:ON) enable
	//
	mHelper->getEnable( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::getState(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * BOOL(OK:EXPIRED) state
	//
	mHelper->getState( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::getTimeout(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * INT timeout (s)
	//
	mHelper->getTimeout( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::ping(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->ping( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::setEnable(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * BOOL(OFF:ON) enable
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setEnable( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::setTimeout(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT timeout (s)
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setTimeout( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}



//-------------------------------------------------------------------------------------------------------------
bool AtlasMplaneOranrrhHeartbeatTestHandler::enableSet(  const std::string& pathname, DataVariant *value, DataVariantList *returnList )
{
	// Setter for "/heartbeat/enable"
	//
	// Use the value passed in as something like:
	//
	//    int newValue = value->toInt() ;
	//

	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<HeartbeatTestHelper> helper(HeartbeatTestHelper::getInstance()) ;
	return helper->enableSet( pathname, value, returnList ) ;
}

//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::enableGet(  const std::string& pathname, DataVariantList *returnList )
{
	// Getter for "/heartbeat/enable"
	//
	// Return the variable value using the returnList using something like:
	//
	//   returnList->find(pathname)->set(someValue) ;
	//

	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<HeartbeatTestHelper> helper(HeartbeatTestHelper::getInstance()) ;
	helper->enableGet( pathname, returnList ) ;
}


//-------------------------------------------------------------------------------------------------------------
bool AtlasMplaneOranrrhHeartbeatTestHandler::timeoutSet(  const std::string& pathname, DataVariant *value, DataVariantList *returnList )
{
	// Setter for "/heartbeat/timeout"
	//
	// Use the value passed in as something like:
	//
	//    int newValue = value->toInt() ;
	//

	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<HeartbeatTestHelper> helper(HeartbeatTestHelper::getInstance()) ;
	return helper->timeoutSet( pathname, value, returnList ) ;
}

//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::timeoutGet(  const std::string& pathname, DataVariantList *returnList )
{
	// Getter for "/heartbeat/timeout"
	//
	// Return the variable value using the returnList using something like:
	//
	//   returnList->find(pathname)->set(someValue) ;
	//

	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<HeartbeatTestHelper> helper(HeartbeatTestHelper::getInstance()) ;
	helper->timeoutGet( pathname, returnList ) ;
}



//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhHeartbeatTestHandler::stateGet(  const std::string& pathname, DataVariantList *returnList )
{
	// Getter for "/heartbeat/state"
	//
	// Return the variable value using the returnList using something like:
	//
	//   returnList->find(pathname)->set(someValue) ;
	//


	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<HeartbeatTestHelper> helper(HeartbeatTestHelper::getInstance()) ;
	helper->stateGet( pathname, returnList ) ;
}








// Add any statics, private methods etc here %%-->

// <--%%