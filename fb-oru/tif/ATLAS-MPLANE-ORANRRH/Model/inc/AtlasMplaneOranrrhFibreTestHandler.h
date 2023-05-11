/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      AtlasMplaneOranrrhFibreTestHandler.h
 * \brief     Test methods for ATLAS-MPLANE-ORANRRH
 *
 *
 * \details   Auto-generated by gentool. Contains test interface definitions. Please add your own
 * code between the %%--> and <--%% comment lines (any code outside these comments will be discarded
 * next time the generate tool is run).
 *
 */

#ifndef __ATLASMPLANEORANRRHFIBRETESTHANDLER__H_
#define __ATLASMPLANEORANRRHFIBRETESTHANDLER__H_


//=============================================================================================================
// INCLUDE
//=============================================================================================================
#include <string>
#include <vector>
#include <memory>
#include "FibreTestHelper.h"
#include "ITif.h"
#include "IRtiMsgParser.h"
#include "Nodes/EntryFunc.h"

// Add any specific includes here %%-->

// <--%%

//=============================================================================================================
// CLASS
//=============================================================================================================

namespace Mplane {

class AtlasMplaneOranrrhFibreTestHandler: public virtual ITifEntry, public EntryFunc
{
public:

	AtlasMplaneOranrrhFibreTestHandler( const std::string& pathname, const std::string& comment,
    		const std::string& callFields, const std::string& returnFields,
    		IRtiMsgParser& msgParser, IRtiSettings& settings);

    virtual ~AtlasMplaneOranrrhFibreTestHandler();

    static void registerMethods(IRtiMsgParser& msgParser, IRtiSettings& settings) ;

	/**
	 * Special constructor - only to be used for calling the static registerMethods()
	 */
	AtlasMplaneOranrrhFibreTestHandler();

	/**
	 * Called by ITif::inject() to get this object to add it's entries
	 * @param tif
	 * @return true if ok
	 */
	virtual bool registerEntry(ITif* tif) override ;

protected:

    virtual std::string operator()(const std::string& functionName) ;

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   FLOAT temp (DegC)
	 *
	 */
	void getTemp( DataVariantList *callList, DataVariantList *returnList );

	/**
	 * Called with:
	 *   INT{0..${MAX_FIBRE}} Index
	 *
	 * Returns:
	 *   ENUM(OK:ERROR) Status=OK
	 *   [STRING Info]
	 *   [STRING Message]
	 *   BOOL(NO:YES) sfpFitted
	 *   BOOL(NO:YES) a0Present
	 *   BOOL(NO:YES) a2Present
	 *   HEXINT[] A0
	 *   HEXINT[] A2
	 *
	 */
	void sfpDump( DataVariantList *callList, DataVariantList *returnList );






// Add any extra methods %%-->

// <--%%

private:
	std::shared_ptr<FibreTestHelper> mHelper ;
};



} // MPLANE

#endif /* __ATLASMPLANEORANRRHFIBRETESTHANDLER__H_*/