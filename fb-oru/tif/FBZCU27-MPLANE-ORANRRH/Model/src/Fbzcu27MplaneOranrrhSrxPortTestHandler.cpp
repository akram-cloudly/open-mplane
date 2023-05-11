/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      Fbzcu27MplaneOranrrhSrxPortTestHandler.cpp
 * \brief     Test methods for FBZCU27-MPLANE-ORANRRH
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
#include "Fbzcu27MplaneOranrrhSrxPortTestHandler.h"

// Add any specific includes here %%-->

// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->

// <--%%


//=============================================================================================================
// STATIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings)
{
	// Create a directory to store the data in
	msgParser.addDir( new DirClass("/srx", "SRx Port settings", msgParser, settings) ) ;


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getAdcRms",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBfs)",
			"Get SRx adc rms value in dB full scale",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getAtten",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dB)",
			"Get SRx attenuator raw value in dBs",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getCorrection",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBm)",
			"Get cal data correction factor used by the sample recevier to correct the power reading",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getFreq",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (kHz)",
			"Get SRx port frequency value",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getFwdPathAdcRms",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBfs)",
			"Get SRx adc rms value in dB full scale for forward direction for a particular channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getFwdPathCorrection",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBm)",
			"Get cal data correction factor used by the sample recevier to correct the forward power reading for a particular channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getFwdPathPower",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBm)",
			"Get cal data corrected sample recevier forward power reading for a particular channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getFwdTssi",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT tssiResult (dBm)",
			"Get forward TSSI value",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getPath",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} channel",
			"Get currently selected sample channel path value",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getPower",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBm)",
			"Get cal data corrected sample recevier power reading for the currently selected channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getRevPathAdcRms",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBfs)",
			"Get SRx adc rms value in dB full scale for reverse direction for a particular channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getRevPathCorrection",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBm)",
			"Get cal data correction factor used by the sample recevier to correct the reverse power reading for a particular channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getRevPathPower",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT value (dBm)",
			"Get cal data corrected sample recevier reverse power reading for a particular channel",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getRevTssi",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT tssiResult (dBm)",
			"Get reverse TSSI value",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/getTemp",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message],FLOAT result (DegC)",
			"Get sample receive path temperature value in degrees C",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/setAtten",
			"INT{1..${NUM_SRX_PORTS}} index,FLOAT value (dB)",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Set SRx attenuator value in dBs",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/setDirection",
			"INT{1..${NUM_SRX_PORTS}} index,ENUM(forward:reverse) direction",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Set power measurement direction for the SRx observation path",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/setFreq",
			"INT{1..${NUM_SRX_PORTS}} index,FLOAT value (kHz)",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Set SRx port frequency value",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/setPath",
			"INT{1..${NUM_SRX_PORTS}} index,INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} channel",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Set SRx observation path",
			msgParser, settings))
	);


	msgParser.add( static_cast<RtiDirEntry *>(new Fbzcu27MplaneOranrrhSrxPortTestHandler("/srx/showSynth",
			"INT{1..${NUM_SRX_PORTS}} index",
			"ENUM(OK:ERROR) Status=OK,[STRING Info],[STRING Message]",
			"Show debug information for the SRx synthesiser",
			msgParser, settings))
	);




	msgParser.add( static_cast<RtiDirEntry *>(new TestReadVar("/srx/Ports", "INT",
			"Number of SRX ports",
			PortsGet,
			msgParser, settings))
	);



}




//=============================================================================================================
// PUBLIC
//=============================================================================================================


//-------------------------------------------------------------------------------------------------------------
Fbzcu27MplaneOranrrhSrxPortTestHandler::Fbzcu27MplaneOranrrhSrxPortTestHandler() :
	EntryFunc("", "", "", "", *ITifControl::NULL_MSG_PARSER, *ITifControl::NULL_SETTINGS),
	mHelper(SrxPortTestHelper::getInstance())
{
	// NOTE: This is a dummy object creator only provided so build features can get access
	// to the registerEntry() method
}

//-------------------------------------------------------------------------------------------------------------
Fbzcu27MplaneOranrrhSrxPortTestHandler::Fbzcu27MplaneOranrrhSrxPortTestHandler(const std::string& pathname, const std::string& callFields,
		const std::string& returnFields, const std::string& comment,
		IRtiMsgParser& msgParser, IRtiSettings& settings) :
	EntryFunc(pathname, comment, callFields, returnFields, msgParser, settings),
	mHelper(SrxPortTestHelper::getInstance())
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
Fbzcu27MplaneOranrrhSrxPortTestHandler::~Fbzcu27MplaneOranrrhSrxPortTestHandler()
{
	// Insert your code here : %%-->

	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
bool Fbzcu27MplaneOranrrhSrxPortTestHandler::registerEntry(ITif* tif)
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
std::string Fbzcu27MplaneOranrrhSrxPortTestHandler::operator()(const std::string& functionName)
{

    if( functionName == "getAdcRms")
    {
        getAdcRms( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getAtten")
    {
        getAtten( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getCorrection")
    {
        getCorrection( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getFreq")
    {
        getFreq( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getFwdPathAdcRms")
    {
        getFwdPathAdcRms( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getFwdPathCorrection")
    {
        getFwdPathCorrection( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getFwdPathPower")
    {
        getFwdPathPower( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getFwdTssi")
    {
        getFwdTssi( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getPath")
    {
        getPath( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getPower")
    {
        getPower( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getRevPathAdcRms")
    {
        getRevPathAdcRms( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getRevPathCorrection")
    {
        getRevPathCorrection( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getRevPathPower")
    {
        getRevPathPower( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getRevTssi")
    {
        getRevTssi( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "getTemp")
    {
        getTemp( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setAtten")
    {
        setAtten( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setDirection")
    {
        setDirection( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setFreq")
    {
        setFreq( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "setPath")
    {
        setPath( callVarList, returnVarList  );
        return "" ;
    }


    if( functionName == "showSynth")
    {
        showSynth( callVarList, returnVarList  );
        return "" ;
    }



    return "";
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getAdcRms(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBfs)
	//
	mHelper->getAdcRms( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getAtten(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dB)
	//
	mHelper->getAtten( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getCorrection(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//
	mHelper->getCorrection( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getFreq(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (kHz)
	//
	mHelper->getFreq( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getFwdPathAdcRms(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBfs)
	//
	mHelper->getFwdPathAdcRms( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getFwdPathCorrection(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//
	mHelper->getFwdPathCorrection( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getFwdPathPower(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//
	mHelper->getFwdPathPower( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getFwdTssi(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT tssiResult (dBm)
	//
	mHelper->getFwdTssi( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getPath(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} channel
	//
	mHelper->getPath( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getPower(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//
	mHelper->getPower( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getRevPathAdcRms(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBfs)
	//
	mHelper->getRevPathAdcRms( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getRevPathCorrection(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//
	mHelper->getRevPathCorrection( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getRevPathPower(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT value (dBm)
	//
	mHelper->getRevPathPower( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getRevTssi(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} path
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT tssiResult (dBm)
	//
	mHelper->getRevTssi( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::getTemp(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * FLOAT result (DegC)
	//
	mHelper->getTemp( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::setAtten(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * FLOAT value (dB)
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setAtten( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::setDirection(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * ENUM(forward:reverse) direction
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setDirection( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::setFreq(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * FLOAT value (kHz)
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setFreq( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::setPath(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// * INT{1..${NUM_TX_PORTS_PER_SRX_PORT}} channel
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->setPath( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::showSynth(  DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT{1..${NUM_SRX_PORTS}} index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//
	mHelper->showSynth( mMsgParser, callList, returnList ) ;

	// Insert your code here : %%-->

	// <--%%
}




//-------------------------------------------------------------------------------------------------------------
void Fbzcu27MplaneOranrrhSrxPortTestHandler::PortsGet(  const std::string& pathname, DataVariantList *returnList )
{
	// Getter for "/srx/Ports"
	//
	// Return the variable value using the returnList using something like:
	//
	//   returnList->find(pathname)->set(someValue) ;
	//


	// Insert your code here : %%-->

	// <--%%

	std::shared_ptr<SrxPortTestHelper> helper(SrxPortTestHelper::getInstance()) ;
	helper->PortsGet( pathname, returnList ) ;
}








// Add any statics, private methods etc here %%-->

// <--%%