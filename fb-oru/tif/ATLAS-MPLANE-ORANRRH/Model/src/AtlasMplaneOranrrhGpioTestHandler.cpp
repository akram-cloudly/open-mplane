/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      AtlasMplaneOranrrhGpioTestHandler.cpp
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
#include "AtlasMplaneOranrrhGpioTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhGpioTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/.gpio", "GPIO control", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhGpioTestHandler("/.gpio/readPort",
			"ENUM(FEM:I2C0) type,INT port",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],UINT value",
			"Read GPIO expander port value",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhGpioTestHandler("/.gpio/show",
			"ENUM(FEM:I2C0) type",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Display debug data",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new AtlasMplaneOranrrhGpioTestHandler("/.gpio/writePort",
			"ENUM(FEM:I2C0) type,INT port,UINT value,UINT mask",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Write a byte to GPIO expander port",
			msgParser, settings))
	);





}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhGpioTestHandler::AtlasMplaneOranrrhGpioTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(GpioTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhGpioTestHandler::AtlasMplaneOranrrhGpioTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(GpioTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
AtlasMplaneOranrrhGpioTestHandler::~AtlasMplaneOranrrhGpioTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool AtlasMplaneOranrrhGpioTestHandler::registerEntry(ITif* tif)
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
std::string AtlasMplaneOranrrhGpioTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "readPort")
    {
        readPort( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "show")
    {
        show( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "writePort")
    {
        writePort( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhGpioTestHandler::readPort(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(FEM:I2C0) type
	// * INT port
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * UINT value
	//
	mHelper->readPort( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void AtlasMplaneOranrrhGpioTestHandler::show(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(FEM:I2C0) type
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
void AtlasMplaneOranrrhGpioTestHandler::writePort(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * ENUM(FEM:I2C0) type
	// * INT port
	// * UINT value
	// * UINT mask
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->writePort( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}










// Add any statics, private methods etc here %%-->

// <--%%