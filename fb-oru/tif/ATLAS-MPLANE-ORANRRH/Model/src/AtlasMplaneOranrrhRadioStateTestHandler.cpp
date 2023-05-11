/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      AtlasMplaneOranrrhRadioStateTestHandler.cpp
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
#include "AtlasMplaneOranrrhRadioStateTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhRadioStateTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/radioState", "Radio state interrogation interface", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhRadioStateTestHandler("/radioState/getState",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Get the current radio state",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhRadioStateTestHandler("/radioState/showAll",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Send debug information about all alarms associated with the RadioState to the log",
			msgParser, settings))
	);





}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhRadioStateTestHandler::AtlasMplaneOranrrhRadioStateTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(RadioStateTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhRadioStateTestHandler::AtlasMplaneOranrrhRadioStateTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(RadioStateTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhRadioStateTestHandler::~AtlasMplaneOranrrhRadioStateTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool AtlasMplaneOranrrhRadioStateTestHandler::registerEntry(ITif* tif)
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
std::string AtlasMplaneOranrrhRadioStateTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "getState")
    {
        getState( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "showAll")
    {
        showAll( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhRadioStateTestHandler::getState(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->getState( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhRadioStateTestHandler::showAll(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->showAll( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}










// Add any statics, private methods etc here %%-->

// <--%%