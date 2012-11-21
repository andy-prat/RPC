/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file MultithreadTestRequestReplyUtils.cxx
 * This source file contains the definition of helpful functions for the DDS messages for interface MultithreadTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "MultithreadTestRequestReplyUtils.h"
#include "MultithreadTestRequestReplyPlugin.h"


const char* MultithreadTest_testRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = MultithreadTest_testRequestTypeSupport::get_type_name();

        if(MultithreadTest_testRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void MultithreadTest_testRequestUtils::setTypeData(MultithreadTest_testRequest& instance, /*in*/ const Dato& dato1)
{
    instance.dato1 = dato1;
    
}

void MultithreadTest_testRequestUtils::extractTypeData(MultithreadTest_testRequest& data, /*in*/ Dato& dato1)
{
    dato1 = data.dato1;  
    
}


const char* MultithreadTest_testReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = MultithreadTest_testReplyTypeSupport::get_type_name();

        if(MultithreadTest_testReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void MultithreadTest_testReplyUtils::setTypeData(MultithreadTest_testReply& instance, /*out*/ const Dato& dato2, /*out*/ DDS_Long test_ret)
{
    instance.dato2 = dato2;
    instance.test_ret = test_ret;            
}

void MultithreadTest_testReplyUtils::extractTypeData(MultithreadTest_testReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*out*/ Dato& dato2, /*out*/ DDS_Long& test_ret)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
    dato2 = data.dato2;  
    test_ret = data.test_ret;            
}

 