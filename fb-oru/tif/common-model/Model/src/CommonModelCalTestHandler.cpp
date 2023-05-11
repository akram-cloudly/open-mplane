/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      CommonModelCalTestHandler.cpp
 * \brief     Test methods for common-model
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run)
 *
 * Add any file header comments here %%-->
 *
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
#include "CommonModelCalTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/cal", "Cal file control", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/getMode",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],ENUM(enable:disable) mode",
			"Get current calibration mode (enable/disable)",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/install",
			"ENUM(${CAL_FILE_TYPES}) type,[STRING url]",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Get and install the specified cal file",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/installStatus",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],BOOL done,BOOL fail,INT totalProgress (%),STRING file,STRING op,INT fileProgress (%),STRING error",
			"Get status of installTcp command",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/installTcp",
			"ENUM(${CAL_FILE_TYPES}) type,INT tcp,INT size,[INT timeout=60]",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Install the cal file type by transferring the data over a TCP port",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/load",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Load the current calibration files into the application",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/setMode",
			"ENUM(enable:disable) mode",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Calibration mode enable/disable",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/show",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Show the currently installed cal files",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new CommonModelCalTestHandler("/cal/showTemperatures",
			"",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Show the initial temperatures that the currently installed cal files were performed at",
			msgParser, settings))
	);



	msgParser.add( static_cast<RtiDirEntry *>(new TestVar("/cal/url", "STRING",
			"Server URL to download from",
			urlGet, urlSet,
			msgParser, settings))
	);




}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
CommonModelCalTestHandler::CommonModelCalTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(CalTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
CommonModelCalTestHandler::CommonModelCalTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(CalTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
CommonModelCalTestHandler::~CommonModelCalTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool CommonModelCalTestHandler::registerEntry(ITif* tif)
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
std::string CommonModelCalTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "getMode")
    {
        getMode( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "install")
    {
        install( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "installStatus")
    {
        installStatus( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "installTcp")
    {
        installTcp( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "load")
    {
        load( callVarList, returnVarList  );
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


    if( functionName == "showTemperatures")
    {
        showTemperatures( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::getMode(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * ENUM(enable:disable) mode
	//
	mHelper->getMode( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::install(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(${CAL_FILE_TYPES}) type
	// * [STRING url]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->install( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::installStatus(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * BOOL done
	// * BOOL fail
	// * INT totalProgress (%)
	// * STRING file
	// * STRING op
	// * INT fileProgress (%)
	// * STRING error
	//
	mHelper->installStatus( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::installTcp(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(${CAL_FILE_TYPES}) type
	// * INT tcp
	// * INT size
	// * [INT timeout=60]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->installTcp( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::load(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->load( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::setMode(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(enable:disable) mode
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
void CommonModelCalTestHandler::show(  DataVariantList *callList, DataVariantList *returnList )
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
void CommonModelCalTestHandler::showTemperatures(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// *
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->showTemperatures( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}



//-------------------------------------------------------------------------------------------------------------
bool CommonModelCalTestHandler::urlSet(  const std::string& pathname, DataVariant *value, DataVariantList *returnList )
{
	// Setter for "/cal/url"
	//
	// Use the value passed in as something like:
	//
	//    int newValue = value->toInt() ;
	//

	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<CalTestHelper> helper(CalTestHelper::getInstance()) ;
	return helper->urlSet( pathname, value, returnList ) ;
}

//-------------------------------------------------------------------------------------------------------------
void CommonModelCalTestHandler::urlGet(  const std::string& pathname, DataVariantList *returnList )
{
	// Getter for "/cal/url"
	//
	// Return the variable value using the returnList using something like:
	//
	//   returnList->find(pathname)->set(someValue) ;
	//

	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<CalTestHelper> helper(CalTestHelper::getInstance()) ;
	helper->urlGet( pathname, returnList ) ;
}









// Add any statics, private methods etc here %%-->

// <--%%