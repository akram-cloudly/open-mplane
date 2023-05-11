/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      FtpTestHelper.h
 * \brief     Test helper for common
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __FTPTESTHELPER__H_
#define __FTPTESTHELPER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "IRtiMsgParser.h"
#include "DataVariant.h"

// Add any specific includes here %%-->

// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class FtpTestHelper
// Add any extra inheritance %%-->

// <--%%
{
public:

	// Add any class settings %%-->

	// <--%%

	// singleton
	static std::shared_ptr<FtpTestHelper> getInstance() ;


	FtpTestHelper();

    virtual ~FtpTestHelper();

	/**
	 * Called with:
	 *   STRING user
	 *   STRING pwd
	 *   STRING server
	 *   STRING filePath
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void put( IRtiMsgParser& msgParser, DataVariantList *callList, DataVariantList *returnList );






// Add any extra methods %%-->
    bool checkState(ReturnType::State ret, const std::string& param, DataVariantList *returnList) const;

// <--%%

};



// Add any Mplane namespace code here %%-->

// <--%%


} // MPLANE

// Add any global namespace code here %%-->

// <--%%


#endif /* __FTPTESTHELPER__H_*/