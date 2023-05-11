/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      Fbzcu27MplaneOranrrhAgcTestHandler.cpp
 * \brief     Test methods for Fbzcu27-MPLANE-ORANRRH
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
#include "Fbzcu27MplaneOranrrhAgcTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhAgcTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/agc", "Rx AGC", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhAgcTestHandler("/agc/getMode",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],ENUM(auto:manual) mode",
			"Get AGC mode (auto/manual)",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhAgcTestHandler("/agc/setMode",
			"ENUM(auto:manual) mode",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"AGC mode auto/manual",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhAgcTestHandler("/agc/show",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Display all settings",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhAgcTestHandler("/agc/showDetail",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Display detailed information about AGC",
			msgParser, settings))
	);





}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
Fbzcu27MplaneOranrrhAgcTestHandler::Fbzcu27MplaneOranrrhAgcTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(AgcTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
Fbzcu27MplaneOranrrhAgcTestHandler::Fbzcu27MplaneOranrrhAgcTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(AgcTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
Fbzcu27MplaneOranrrhAgcTestHandler::~Fbzcu27MplaneOranrrhAgcTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool Fbzcu27MplaneOranrrhAgcTestHandler::registerEntry(ITif* tif)
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
std::string Fbzcu27MplaneOranrrhAgcTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "getMode")
    {
        getMode( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setMode")
    {
        setMode( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "show")
    {
        show( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "showDetail")
    {
        showDetail( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhAgcTestHandler::getMode(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * ENUM(auto:manual) mode
	//
	mHelper->getMode( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhAgcTestHandler::setMode(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(auto:manual) mode
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setMode( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhAgcTestHandler::show(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->show( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhAgcTestHandler::showDetail(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->showDetail( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}










// Add any statics, private methods etc here %%-->

// <--%%