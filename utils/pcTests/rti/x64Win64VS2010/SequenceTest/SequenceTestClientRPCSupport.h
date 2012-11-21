/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file SequenceTestClientRPCSupport.h
 * This header file contains the declaration of the proxy's RPC endpoints for interface SequenceTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _SequenceTest_CLIENT_RPC_SUPPORT_H_
#define _SequenceTest_CLIENT_RPC_SUPPORT_H_

#include "utils/GenericClientRPC.h"
#include "SequenceTestRequestReplySupport.h"


GENERIC_CLIENT_RPC(SequenceTest_getSLongClientRPC, SequenceTest_getSLongRequestDataWriter, SequenceTest_getSLongReplyDataReader);


GENERIC_CLIENT_RPC(SequenceTest_getStringClientRPC, SequenceTest_getStringRequestDataWriter, SequenceTest_getStringReplyDataReader);


GENERIC_CLIENT_RPC(SequenceTest_getStringBoundedClientRPC, SequenceTest_getStringBoundedRequestDataWriter, SequenceTest_getStringBoundedReplyDataReader);


#endif  // _SequenceTest_CLIENT_RPC_SUPPORT_H_