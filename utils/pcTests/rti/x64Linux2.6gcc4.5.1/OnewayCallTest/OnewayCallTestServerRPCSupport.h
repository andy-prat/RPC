/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file OnewayCallTestServerRPCSupport.h
 * This header file contains the declaration of the server's RPC endpoints for interface OnewayCallTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _OnewayCallTest_SERVER_RPC_SUPPORT_H_
#define _OnewayCallTest_SERVER_RPC_SUPPORT_H_

#include "utils/GenericServerRPC.h"
#include "OnewayCallTestRequestReplySupport.h"



GENERIC_SERVER_ONEWAY_RPC(OnewayCallTest_setLongServerRPC, OnewayCallTest_setLongRequestDataReader);


GENERIC_SERVER_RPC(OnewayCallTest_getLongServerRPC, OnewayCallTest_getLongReplyDataWriter, OnewayCallTest_getLongRequestDataReader);


GENERIC_SERVER_ONEWAY_RPC(OnewayCallTest_setBooleanServerRPC, OnewayCallTest_setBooleanRequestDataReader);


GENERIC_SERVER_RPC(OnewayCallTest_getBooleanServerRPC, OnewayCallTest_getBooleanReplyDataWriter, OnewayCallTest_getBooleanRequestDataReader);


GENERIC_SERVER_ONEWAY_RPC(OnewayCallTest_setStringServerRPC, OnewayCallTest_setStringRequestDataReader);


GENERIC_SERVER_RPC(OnewayCallTest_getStringServerRPC, OnewayCallTest_getStringReplyDataWriter, OnewayCallTest_getStringRequestDataReader);


GENERIC_SERVER_ONEWAY_RPC(OnewayCallTest_setStructServerRPC, OnewayCallTest_setStructRequestDataReader);


GENERIC_SERVER_RPC(OnewayCallTest_getStructServerRPC, OnewayCallTest_getStructReplyDataWriter, OnewayCallTest_getStructRequestDataReader);


#endif  // _OnewayCallTest_SERVER_RPC_SUPPORT_H_