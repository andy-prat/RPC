/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file ServerExceptionRequestReplyUtils.cxx
 * This source file contains the definition of helpful functions for the DDS messages for interface ServerException.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ServerExceptionRequestReplyUtils.h"
#include "ServerExceptionRequestReplyPlugin.h"


const char* ServerException_sendExceptionRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = ServerException_sendExceptionRequestTypeSupport::get_type_name();

        if(ServerException_sendExceptionRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void ServerException_sendExceptionRequestUtils::setTypeData(ServerException_sendExceptionRequest& instance)
{
    
}

void ServerException_sendExceptionRequestUtils::extractTypeData(ServerException_sendExceptionRequest& data)
{
  
    
}


const char* ServerException_sendExceptionReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = ServerException_sendExceptionReplyTypeSupport::get_type_name();

        if(ServerException_sendExceptionReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void ServerException_sendExceptionReplyUtils::setTypeData(ServerException_sendExceptionReply& instance)
{
    
}

void ServerException_sendExceptionReplyUtils::extractTypeData(ServerException_sendExceptionReply& data, eProsima::RPCDDS::ReturnMessage& retcode)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
  
    
}


const char* ServerException_sendExceptionTwoRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = ServerException_sendExceptionTwoRequestTypeSupport::get_type_name();

        if(ServerException_sendExceptionTwoRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void ServerException_sendExceptionTwoRequestUtils::setTypeData(ServerException_sendExceptionTwoRequest& instance, /*in*/ char* message, /*inout*/ char* message2)
{
    instance.message = message;
    instance.message2 = message2;
    
}

void ServerException_sendExceptionTwoRequestUtils::extractTypeData(ServerException_sendExceptionTwoRequest& data, /*in*/ char*& message, /*inout*/ char*& message2)
{
    message = data.message;
    message2 = strdup(data.message2);  
    
}


const char* ServerException_sendExceptionTwoReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = ServerException_sendExceptionTwoReplyTypeSupport::get_type_name();

        if(ServerException_sendExceptionTwoReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void ServerException_sendExceptionTwoReplyUtils::setTypeData(ServerException_sendExceptionTwoReply& instance, /*inout*/ char* message2, /*out*/ char* message3, /*out*/ char* sendExceptionTwo_ret)
{
    instance.message2 = message2;
    instance.message3 = message3;
    instance.sendExceptionTwo_ret = sendExceptionTwo_ret;            
}

void ServerException_sendExceptionTwoReplyUtils::extractTypeData(ServerException_sendExceptionTwoReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*inout*/ char*& message2, /*out*/ char*& message3, /*out*/ char*& sendExceptionTwo_ret)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
    if(message2 != NULL)
    	free(message2);message2 = data.message2;
    message3 = data.message3;  
    sendExceptionTwo_ret = data.sendExceptionTwo_ret;            
}


const char* ServerException_sendExceptionThreeRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = ServerException_sendExceptionThreeRequestTypeSupport::get_type_name();

        if(ServerException_sendExceptionThreeRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void ServerException_sendExceptionThreeRequestUtils::setTypeData(ServerException_sendExceptionThreeRequest& instance, /*in*/ const Estructura& es, /*inout*/ const Estructura& es2)
{
    instance.es = es;
    instance.es2 = es2;
    
}

void ServerException_sendExceptionThreeRequestUtils::extractTypeData(ServerException_sendExceptionThreeRequest& data, /*in*/ Estructura& es, /*inout*/ Estructura& es2)
{
    es = data.es;
    EstructuraPluginSupport_copy_data(&es2, &data.es2);  
    
}


const char* ServerException_sendExceptionThreeReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = ServerException_sendExceptionThreeReplyTypeSupport::get_type_name();

        if(ServerException_sendExceptionThreeReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void ServerException_sendExceptionThreeReplyUtils::setTypeData(ServerException_sendExceptionThreeReply& instance, /*inout*/ const Estructura& es2, /*out*/ const Estructura& es3, /*out*/ const Estructura& sendExceptionThree_ret)
{
    instance.es2 = es2;
    instance.es3 = es3;
    instance.sendExceptionThree_ret = sendExceptionThree_ret;            
}

void ServerException_sendExceptionThreeReplyUtils::extractTypeData(ServerException_sendExceptionThreeReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*inout*/ Estructura& es2, /*out*/ Estructura& es3, /*out*/ Estructura& sendExceptionThree_ret)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
    Estructura_finalize(&es2);es2 = data.es2;
    es3 = data.es3;  
    sendExceptionThree_ret = data.sendExceptionThree_ret;            
}

 