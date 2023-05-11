/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      LedTestHelper.cpp
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
#include "LedTestHelper.h"

// Add any specific includes here %%-->


// <--%%


using namespace Mplane ;

// Add any statics, types, prototypes etc here %%-->


// <--%%



//=============================================================================================================
// SINGLETON
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<LedTestHelper> LedTestHelper::getInstance()
{
	static std::shared_ptr<LedTestHelper> instance(std::make_shared<LedTestHelper>()) ;
	return instance ;
}

//=============================================================================================================
// PUBLIC
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
LedTestHelper::LedTestHelper()
// Insert additional inheritance constructors here : %%-->

// <--%%
{
	// Insert your code here : %%-->


	// <--%%
}

//-------------------------------------------------------------------------------------------------------------
LedTestHelper::~LedTestHelper()
{
	// Insert your code here : %%-->


	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void LedTestHelper::get( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT index
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	// * ENUM(red:amber:yellow:green) colour
	// * ENUM(on:off:flash:breath) state
	// * [INT rate]
	//

	// Insert your code here : %%-->
    ReturnType::State ret = ReturnType::RT_OK;

    std::shared_ptr<ILedControl> ledControl = getLedInterface(   callList, returnList );

    int numberOfLeds = ledControl->getNumberOfLeds();

    int index = ((callList->find("index")->toInt()));

    // Bounds check the index against the number of leds that are actually supported.
    if (index < numberOfLeds)
    {
        std::shared_ptr<Mplane::ILed> ledPtr = ledControl->getLed(index);

        DataVariant *state = returnList->find("state");
        // get the state to apply
        if( ledPtr->getState() == ILed::LED_ON )
        {
            state->set("ON");
        }
        else if( ledPtr->getState() == ILed::LED_OFF )
        {
            state->set("OFF");
        }
        else if( ledPtr->getState() == ILed::LED_FLASH )
        {
            state->set("FLASH");
        }
        else if( ledPtr->getState() == ILed::LED_BREATH )
        {
            state->set("BREATH");
        }


        DataVariant *colour = returnList->find("colour");

        if( ledPtr->getColour() == ILed::LED_RED )
        {
            colour->set("RED");
        }
        else if( ledPtr->getColour() == ILed::LED_AMBER )
        {
            colour->set("AMBER");
        }
        else if( ledPtr->getColour() == ILed::LED_YELLOW )
        {
            colour->set("YELLOW");
        }
        else if( ledPtr->getColour() == ILed::LED_GREEN )
        {
            colour->set("GREEN");
        }

        DataVariant *rate = returnList->find("rate");
        rate->setUint(ledPtr->getRate());

    }
    else
    {
        ret = ReturnType::RT_OUT_OF_RANGE;
    }
    // Check to see if the return value is anything other than RT_OK. This will
    // provide error feedback or just return a value result of 0 if everything is
    // ok.
    checkState(ret, "value", returnList);
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void LedTestHelper::indicate( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * [UINT time=2000ms (ms)]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
    std::shared_ptr<ILedControl> ledControl = getLedInterface( callList, returnList );
    ledControl->groupIndicate(callList->find("time")->toUint()) ;
	// <--%%
}


//-------------------------------------------------------------------------------------------------------------
void LedTestHelper::set( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList )
{
	// Called with:
	// * INT index
	// * ENUM(red:amber:yellow:green) colour
	// * ENUM(on:off:flash:breath) state
	// * [INT rate]
	// Returns:
	// * ENUM(OK:ERROR) Status=OK
	// * [STRING Info]
	// * [STRING Message]
	//

	// Insert your code here : %%-->
    ReturnType::State ret = ReturnType::RT_OK;

    std::shared_ptr<ILedControl> ledControl = getLedInterface(   callList, returnList );

    UINT8 numberOfLeds = ledControl->getNumberOfLeds();

    UINT8 index = ((callList->find("index")->toInt()));

    // Bounds check the index against the number of leds that are actually supported.
    if (index < numberOfLeds)
    {
        // get the state to apply
        if (callList->find("state")->toString() == "on")
        {
            ledControl->setState(index, ILed::LED_ON);
        }
        else if (callList->find("state")->toString() == "off")
        {
            ledControl->setState(index, ILed::LED_OFF);
        }
        else if (callList->find("state")->toString() == "flash")
        {
            ledControl->setState(index, ILed::LED_FLASH);
        }
        else if (callList->find("state")->toString() == "breath")
        {
            ledControl->setState(index, ILed::LED_BREATH);
        }
        else // Any other state is not supported!
        {
            ret = ReturnType::RT_OUT_OF_RANGE;
        }

        // get the colour to apply
        if (callList->find("colour")->toString() == "red")
        {
            ret = ledControl->setColour(index, ILed::LED_RED);
        }
        else if (callList->find("colour")->toString() == "amber")
        {
            ret = ledControl->setColour(index, ILed::LED_AMBER);
        }
        else if (callList->find("colour")->toString() == "yellow")
        {
            ret = ledControl->setColour(index, ILed::LED_YELLOW);
        }
        else if (callList->find("colour")->toString() == "green")
        {
            ret = ledControl->setColour(index, ILed::LED_GREEN);
        }
        else
        {
            ret = ReturnType::RT_OUT_OF_RANGE;
        }

        // Check that the set colour was good
        if(ReturnType::RT_OK == ret)
        {
            // get the rate to apply
            UINT8 rate = callList->find("rate")->toInt();

            if( rate > 0xff )
            {
                ret = ReturnType::RT_OUT_OF_RANGE;
            }
            else
            {
                ret = ledControl->setRate(index, rate);
            }
        }
    }
    else
    {
        ret = ReturnType::RT_OUT_OF_RANGE;
    }
    // Check to see if the return value is anything other than RT_OK. This will
    // provide error feedback or just return a value result of 0 if everything is
    // ok.
    checkState(ret, "value", returnList);

	// <--%%
}










// Add any statics, private methods etc here %%-->

//-------------------------------------------------------------------------------------------------------------
std::shared_ptr<ILedControl> LedTestHelper::getLedInterface(DataVariantList *callList, DataVariantList *returnList) const
{
#if 0
	/*
     * Get the instance of the LED object that was generated in the device list.
     * This means that if the board is not supported it will be correctly handled
     * by the LED object.
     */
    std::shared_ptr<IRadio>radio( IRadioFactory::getInterface() );
    std::shared_ptr<ILedControl> ledInstance = radio->getDevices().getLed( 0 );
#endif

    std::shared_ptr<ILedControl> ledInstance(ILedControl::getInterface()) ;
    return ledInstance;
}

//-------------------------------------------------------------------------------------------------------------
bool LedTestHelper::checkState(ReturnType::State ret, const std::string& param, DataVariantList *returnList) const
{
    if (ret != ReturnType::RT_OK)
    {
        // set an error
        returnList->find(RtiKeyword::STATUS_VAR)->set( RtiKeyword::StatusERROR );

        std::stringstream ss ;
        ss << "Unable to set " << param << " : ERROR" << ReturnType::getState(ret) ;
        returnList->find(RtiKeyword::MESSAGE_VAR)->set(ss.str()) ;

        return false ;
    }

    return true ;
}

// <--%%