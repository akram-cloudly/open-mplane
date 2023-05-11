/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      HelperImagesLibTestHandler.h
 * \brief     Test methods for Helper
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __HELPERIMAGESLIBTESTHANDLER__H_
#define __HELPERIMAGESLIBTESTHANDLER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "ImagesLibTestHelper.h"
#include "IRtiMsgParser.h"
#include "Nodes/EntryFunc.h"

// Add any specific includes here %%-->

// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class HelperImagesLibTestHandler: public EntryFunc
{
public:

	HelperImagesLibTestHandler( const std::string& pathname, const std::string& comment,
    		const std::string& callFields, const std::string& returnFields,
    		IRtiMsgParser& msgParser, IRtiSettings& settings);

    virtual ~HelperImagesLibTestHandler();

    static void registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings) ;

protected:

    virtual std::string operator()(const std::string& functionName) ;

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
	void clean( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   STRING version
	 *   STRING build
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void install( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   STRING filename
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *
	 */
	void installFile( DataVariantList *callList, DataVariantList *returnList );

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
	void show( DataVariantList *callList, DataVariantList *returnList );






// Add any extra methods %%-->

// <--%%

private:
	std::shared_ptr<ImagesLibTestHelper> mHelper ;
};



} // Mplane

#endif /* __HELPERIMAGESLIBTESTHANDLER__H_*/