/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file BasicTypeTestProxy.cxx
 * This source file contains the definition of the proxy for interface BasicTypeTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "BasicTypeTestProxy.h"
#include "client/ClientRPC.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "BasicTypeTestRequestReplyPlugin.h"
#include "BasicTypeTestAsyncSupport.h"
#include "exceptions/Exceptions.h"

BasicTypeTestProxy::BasicTypeTestProxy(std::string remoteServiceName, int domainId, long timeout) :
    Client(remoteServiceName, NULL, domainId, timeout)
{
    createRPCs();
}

BasicTypeTestProxy::BasicTypeTestProxy(std::string remoteServiceName, eProsima::RPCDDS::Transport *transport, int domainId, long timeout) :
    Client(remoteServiceName, transport, domainId, timeout)
{
    createRPCs();
}

BasicTypeTestProxy::~BasicTypeTestProxy()
{
    delete getOctet_Service;
    delete getChar_Service;
    delete getWChar_Service;
    delete getShort_Service;
    delete getUShort_Service;
    delete getLong_Service;
    delete getULong_Service;
    delete getLLong_Service;
    delete getULLong_Service;
    delete getFloat_Service;
    delete getDouble_Service;
    delete getBoolean_Service;
}

void BasicTypeTestProxy::createRPCs()
{
    this->getOctet_Service = new BasicTypeTest_getOctetClientRPC("getOctet",
                                  BasicTypeTest_getOctetRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getOctetReplyUtils::registerType(getParticipant()),
                                  this);
    this->getChar_Service = new BasicTypeTest_getCharClientRPC("getChar",
                                  BasicTypeTest_getCharRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getCharReplyUtils::registerType(getParticipant()),
                                  this);
    this->getWChar_Service = new BasicTypeTest_getWCharClientRPC("getWChar",
                                  BasicTypeTest_getWCharRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getWCharReplyUtils::registerType(getParticipant()),
                                  this);
    this->getShort_Service = new BasicTypeTest_getShortClientRPC("getShort",
                                  BasicTypeTest_getShortRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getShortReplyUtils::registerType(getParticipant()),
                                  this);
    this->getUShort_Service = new BasicTypeTest_getUShortClientRPC("getUShort",
                                  BasicTypeTest_getUShortRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getUShortReplyUtils::registerType(getParticipant()),
                                  this);
    this->getLong_Service = new BasicTypeTest_getLongClientRPC("getLong",
                                  BasicTypeTest_getLongRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getLongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getULong_Service = new BasicTypeTest_getULongClientRPC("getULong",
                                  BasicTypeTest_getULongRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getULongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getLLong_Service = new BasicTypeTest_getLLongClientRPC("getLLong",
                                  BasicTypeTest_getLLongRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getLLongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getULLong_Service = new BasicTypeTest_getULLongClientRPC("getULLong",
                                  BasicTypeTest_getULLongRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getULLongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getFloat_Service = new BasicTypeTest_getFloatClientRPC("getFloat",
                                  BasicTypeTest_getFloatRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getFloatReplyUtils::registerType(getParticipant()),
                                  this);
    this->getDouble_Service = new BasicTypeTest_getDoubleClientRPC("getDouble",
                                  BasicTypeTest_getDoubleRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getDoubleReplyUtils::registerType(getParticipant()),
                                  this);
    this->getBoolean_Service = new BasicTypeTest_getBooleanClientRPC("getBoolean",
                                  BasicTypeTest_getBooleanRequestUtils::registerType(getParticipant()),
                                  BasicTypeTest_getBooleanReplyUtils::registerType(getParticipant()),
                                  this);

}

 
DDS_Octet BasicTypeTestProxy::getOctet(/*in*/ DDS_Octet oc1, /*inout*/ DDS_Octet& oc2, /*out*/ DDS_Octet& oc3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Octet  getOctet_ret = 0;
    BasicTypeTest_getOctetRequest instance;
    BasicTypeTest_getOctetReply retInstance;

    BasicTypeTest_getOctetReply_initialize(&retInstance);
    BasicTypeTest_getOctetRequestUtils::setTypeData(instance, oc1, oc2);
    retcode = getOctet_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getOctetReplyUtils::extractTypeData(retInstance, retcode, oc2, oc3, getOctet_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getOctet_ret;
}
 
DDS_Char BasicTypeTestProxy::getChar(/*in*/ DDS_Char ch1, /*inout*/ DDS_Char& ch2, /*out*/ DDS_Char& ch3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Char  getChar_ret = 0;
    BasicTypeTest_getCharRequest instance;
    BasicTypeTest_getCharReply retInstance;

    BasicTypeTest_getCharReply_initialize(&retInstance);
    BasicTypeTest_getCharRequestUtils::setTypeData(instance, ch1, ch2);
    retcode = getChar_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getCharReplyUtils::extractTypeData(retInstance, retcode, ch2, ch3, getChar_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getChar_ret;
}
 
DDS_Wchar BasicTypeTestProxy::getWChar(/*in*/ DDS_Wchar wch1, /*inout*/ DDS_Wchar& wch2, /*out*/ DDS_Wchar& wch3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Wchar  getWChar_ret = 0;
    BasicTypeTest_getWCharRequest instance;
    BasicTypeTest_getWCharReply retInstance;

    BasicTypeTest_getWCharReply_initialize(&retInstance);
    BasicTypeTest_getWCharRequestUtils::setTypeData(instance, wch1, wch2);
    retcode = getWChar_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getWCharReplyUtils::extractTypeData(retInstance, retcode, wch2, wch3, getWChar_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getWChar_ret;
}
 
DDS_Short BasicTypeTestProxy::getShort(/*in*/ DDS_Short sh1, /*inout*/ DDS_Short& sh2, /*out*/ DDS_Short& sh3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Short  getShort_ret = 0;
    BasicTypeTest_getShortRequest instance;
    BasicTypeTest_getShortReply retInstance;

    BasicTypeTest_getShortReply_initialize(&retInstance);
    BasicTypeTest_getShortRequestUtils::setTypeData(instance, sh1, sh2);
    retcode = getShort_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getShortReplyUtils::extractTypeData(retInstance, retcode, sh2, sh3, getShort_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getShort_ret;
}
 
DDS_UnsignedShort BasicTypeTestProxy::getUShort(/*in*/ DDS_UnsignedShort ush1, /*inout*/ DDS_UnsignedShort& ush2, /*out*/ DDS_UnsignedShort& ush3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_UnsignedShort  getUShort_ret = 0;
    BasicTypeTest_getUShortRequest instance;
    BasicTypeTest_getUShortReply retInstance;

    BasicTypeTest_getUShortReply_initialize(&retInstance);
    BasicTypeTest_getUShortRequestUtils::setTypeData(instance, ush1, ush2);
    retcode = getUShort_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getUShortReplyUtils::extractTypeData(retInstance, retcode, ush2, ush3, getUShort_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getUShort_ret;
}
 
DDS_Long BasicTypeTestProxy::getLong(/*in*/ DDS_Long lo1, /*inout*/ DDS_Long& lo2, /*out*/ DDS_Long& lo3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Long  getLong_ret = 0;
    BasicTypeTest_getLongRequest instance;
    BasicTypeTest_getLongReply retInstance;

    BasicTypeTest_getLongReply_initialize(&retInstance);
    BasicTypeTest_getLongRequestUtils::setTypeData(instance, lo1, lo2);
    retcode = getLong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getLongReplyUtils::extractTypeData(retInstance, retcode, lo2, lo3, getLong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getLong_ret;
}
 
DDS_UnsignedLong BasicTypeTestProxy::getULong(/*in*/ DDS_UnsignedLong ulo1, /*inout*/ DDS_UnsignedLong& ulo2, /*out*/ DDS_UnsignedLong& ulo3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_UnsignedLong  getULong_ret = 0;
    BasicTypeTest_getULongRequest instance;
    BasicTypeTest_getULongReply retInstance;

    BasicTypeTest_getULongReply_initialize(&retInstance);
    BasicTypeTest_getULongRequestUtils::setTypeData(instance, ulo1, ulo2);
    retcode = getULong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getULongReplyUtils::extractTypeData(retInstance, retcode, ulo2, ulo3, getULong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getULong_ret;
}
 
DDS_LongLong BasicTypeTestProxy::getLLong(/*in*/ DDS_LongLong llo1, /*inout*/ DDS_LongLong& llo2, /*out*/ DDS_LongLong& llo3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_LongLong  getLLong_ret = 0;
    BasicTypeTest_getLLongRequest instance;
    BasicTypeTest_getLLongReply retInstance;

    BasicTypeTest_getLLongReply_initialize(&retInstance);
    BasicTypeTest_getLLongRequestUtils::setTypeData(instance, llo1, llo2);
    retcode = getLLong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getLLongReplyUtils::extractTypeData(retInstance, retcode, llo2, llo3, getLLong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getLLong_ret;
}
 
DDS_UnsignedLongLong BasicTypeTestProxy::getULLong(/*in*/ DDS_UnsignedLongLong ullo1, /*inout*/ DDS_UnsignedLongLong& ullo2, /*out*/ DDS_UnsignedLongLong& ullo3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_UnsignedLongLong  getULLong_ret = 0;
    BasicTypeTest_getULLongRequest instance;
    BasicTypeTest_getULLongReply retInstance;

    BasicTypeTest_getULLongReply_initialize(&retInstance);
    BasicTypeTest_getULLongRequestUtils::setTypeData(instance, ullo1, ullo2);
    retcode = getULLong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getULLongReplyUtils::extractTypeData(retInstance, retcode, ullo2, ullo3, getULLong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getULLong_ret;
}
 
DDS_Float BasicTypeTestProxy::getFloat(/*in*/ DDS_Float fl1, /*inout*/ DDS_Float& fl2, /*out*/ DDS_Float& fl3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Float  getFloat_ret = 0;
    BasicTypeTest_getFloatRequest instance;
    BasicTypeTest_getFloatReply retInstance;

    BasicTypeTest_getFloatReply_initialize(&retInstance);
    BasicTypeTest_getFloatRequestUtils::setTypeData(instance, fl1, fl2);
    retcode = getFloat_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getFloatReplyUtils::extractTypeData(retInstance, retcode, fl2, fl3, getFloat_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getFloat_ret;
}
 
DDS_Double BasicTypeTestProxy::getDouble(/*in*/ DDS_Double do1, /*inout*/ DDS_Double& do2, /*out*/ DDS_Double& do3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Double  getDouble_ret = 0;
    BasicTypeTest_getDoubleRequest instance;
    BasicTypeTest_getDoubleReply retInstance;

    BasicTypeTest_getDoubleReply_initialize(&retInstance);
    BasicTypeTest_getDoubleRequestUtils::setTypeData(instance, do1, do2);
    retcode = getDouble_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getDoubleReplyUtils::extractTypeData(retInstance, retcode, do2, do3, getDouble_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getDouble_ret;
}
 
DDS_Boolean BasicTypeTestProxy::getBoolean(/*in*/ DDS_Boolean bo1, /*inout*/ DDS_Boolean& bo2, /*out*/ DDS_Boolean& bo3) 
{
    eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    DDS_Boolean  getBoolean_ret = RTI_FALSE;
    BasicTypeTest_getBooleanRequest instance;
    BasicTypeTest_getBooleanReply retInstance;

    BasicTypeTest_getBooleanReply_initialize(&retInstance);
    BasicTypeTest_getBooleanRequestUtils::setTypeData(instance, bo1, bo2);
    retcode = getBoolean_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::RPCDDS::OPERATION_SUCCESSFUL)
    {
        BasicTypeTest_getBooleanReplyUtils::extractTypeData(retInstance, retcode, bo2, bo3, getBoolean_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
            throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::RPCDDS::SERVER_TIMEOUT:
            throw eProsima::RPCDDS::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::RPCDDS::SERVER_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ServerInternalException(retInstance.header.rpcddsRetMsg);
            break;
    };
    

    return getBoolean_ret;
}

 
void BasicTypeTestProxy::getOctet_async(BasicTypeTest_getOctetCallbackHandler &obj, /*in*/ DDS_Octet oc1, /*inout*/ DDS_Octet oc2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getOctetRequest instance;
    BasicTypeTest_getOctetTask *task = NULL;
    BasicTypeTest_getOctetRequestUtils::setTypeData(instance, oc1, oc2);
    task = new BasicTypeTest_getOctetTask(obj, this);
    retcode = getOctet_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getChar_async(BasicTypeTest_getCharCallbackHandler &obj, /*in*/ DDS_Char ch1, /*inout*/ DDS_Char ch2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getCharRequest instance;
    BasicTypeTest_getCharTask *task = NULL;
    BasicTypeTest_getCharRequestUtils::setTypeData(instance, ch1, ch2);
    task = new BasicTypeTest_getCharTask(obj, this);
    retcode = getChar_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getWChar_async(BasicTypeTest_getWCharCallbackHandler &obj, /*in*/ DDS_Wchar wch1, /*inout*/ DDS_Wchar wch2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getWCharRequest instance;
    BasicTypeTest_getWCharTask *task = NULL;
    BasicTypeTest_getWCharRequestUtils::setTypeData(instance, wch1, wch2);
    task = new BasicTypeTest_getWCharTask(obj, this);
    retcode = getWChar_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getShort_async(BasicTypeTest_getShortCallbackHandler &obj, /*in*/ DDS_Short sh1, /*inout*/ DDS_Short sh2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getShortRequest instance;
    BasicTypeTest_getShortTask *task = NULL;
    BasicTypeTest_getShortRequestUtils::setTypeData(instance, sh1, sh2);
    task = new BasicTypeTest_getShortTask(obj, this);
    retcode = getShort_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getUShort_async(BasicTypeTest_getUShortCallbackHandler &obj, /*in*/ DDS_UnsignedShort ush1, /*inout*/ DDS_UnsignedShort ush2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getUShortRequest instance;
    BasicTypeTest_getUShortTask *task = NULL;
    BasicTypeTest_getUShortRequestUtils::setTypeData(instance, ush1, ush2);
    task = new BasicTypeTest_getUShortTask(obj, this);
    retcode = getUShort_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getLong_async(BasicTypeTest_getLongCallbackHandler &obj, /*in*/ DDS_Long lo1, /*inout*/ DDS_Long lo2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getLongRequest instance;
    BasicTypeTest_getLongTask *task = NULL;
    BasicTypeTest_getLongRequestUtils::setTypeData(instance, lo1, lo2);
    task = new BasicTypeTest_getLongTask(obj, this);
    retcode = getLong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getULong_async(BasicTypeTest_getULongCallbackHandler &obj, /*in*/ DDS_UnsignedLong ulo1, /*inout*/ DDS_UnsignedLong ulo2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getULongRequest instance;
    BasicTypeTest_getULongTask *task = NULL;
    BasicTypeTest_getULongRequestUtils::setTypeData(instance, ulo1, ulo2);
    task = new BasicTypeTest_getULongTask(obj, this);
    retcode = getULong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getLLong_async(BasicTypeTest_getLLongCallbackHandler &obj, /*in*/ DDS_LongLong llo1, /*inout*/ DDS_LongLong llo2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getLLongRequest instance;
    BasicTypeTest_getLLongTask *task = NULL;
    BasicTypeTest_getLLongRequestUtils::setTypeData(instance, llo1, llo2);
    task = new BasicTypeTest_getLLongTask(obj, this);
    retcode = getLLong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getULLong_async(BasicTypeTest_getULLongCallbackHandler &obj, /*in*/ DDS_UnsignedLongLong ullo1, /*inout*/ DDS_UnsignedLongLong ullo2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getULLongRequest instance;
    BasicTypeTest_getULLongTask *task = NULL;
    BasicTypeTest_getULLongRequestUtils::setTypeData(instance, ullo1, ullo2);
    task = new BasicTypeTest_getULLongTask(obj, this);
    retcode = getULLong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getFloat_async(BasicTypeTest_getFloatCallbackHandler &obj, /*in*/ DDS_Float fl1, /*inout*/ DDS_Float fl2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getFloatRequest instance;
    BasicTypeTest_getFloatTask *task = NULL;
    BasicTypeTest_getFloatRequestUtils::setTypeData(instance, fl1, fl2);
    task = new BasicTypeTest_getFloatTask(obj, this);
    retcode = getFloat_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getDouble_async(BasicTypeTest_getDoubleCallbackHandler &obj, /*in*/ DDS_Double do1, /*inout*/ DDS_Double do2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getDoubleRequest instance;
    BasicTypeTest_getDoubleTask *task = NULL;
    BasicTypeTest_getDoubleRequestUtils::setTypeData(instance, do1, do2);
    task = new BasicTypeTest_getDoubleTask(obj, this);
    retcode = getDouble_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getBoolean_async(BasicTypeTest_getBooleanCallbackHandler &obj, /*in*/ DDS_Boolean bo1, /*inout*/ DDS_Boolean bo2) 
{
	eProsima::RPCDDS::ReturnMessage retcode = eProsima::RPCDDS::CLIENT_INTERNAL_ERROR;
    BasicTypeTest_getBooleanRequest instance;
    BasicTypeTest_getBooleanTask *task = NULL;
    BasicTypeTest_getBooleanRequestUtils::setTypeData(instance, bo1, bo2);
    task = new BasicTypeTest_getBooleanTask(obj, this);
    retcode = getBoolean_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::RPCDDS::CLIENT_INTERNAL_ERROR:
            throw eProsima::RPCDDS::ClientInternalException("Error in client side");
            break;
        case eProsima::RPCDDS::NO_SERVER:
             throw eProsima::RPCDDS::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}