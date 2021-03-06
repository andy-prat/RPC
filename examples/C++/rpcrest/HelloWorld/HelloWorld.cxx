/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * _LICENSE file included in this  distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorld.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "HelloWorld.h"

#include "rpcrest/exceptions/BadParamException.h"
using namespace eprosima::rpc::exception;

#include <utility>

HelloWorld::HelloWorldResource::EmptyHelloResponse::EmptyHelloResponse()
{
    m_status = 0;
}

HelloWorld::HelloWorldResource::EmptyHelloResponse::~EmptyHelloResponse()
{
}

HelloWorld::HelloWorldResource::EmptyHelloResponse::EmptyHelloResponse(const EmptyHelloResponse &x)
{
    m_status = x.m_status;
}

HelloWorld::HelloWorldResource::EmptyHelloResponse::EmptyHelloResponse(EmptyHelloResponse &&x)
{
    m_status = x.m_status;
}

HelloWorld::HelloWorldResource::EmptyHelloResponse& HelloWorld::HelloWorldResource::EmptyHelloResponse::operator=(const EmptyHelloResponse &x)
{
    m_status = x.m_status;
    
    return *this;
}

HelloWorld::HelloWorldResource::EmptyHelloResponse& HelloWorld::HelloWorldResource::EmptyHelloResponse::operator=(EmptyHelloResponse &&x)
{
    m_status = x.m_status;
    
    return *this;
}


HelloWorld::HelloWorldResource::XMLHelloResponse::XMLHelloResponse()
{
    m_status = 0;
    m_xmlRepresentation = "";
}

HelloWorld::HelloWorldResource::XMLHelloResponse::~XMLHelloResponse()
{
}

HelloWorld::HelloWorldResource::XMLHelloResponse::XMLHelloResponse(const XMLHelloResponse &x)
{
    m_status = x.m_status;
    m_xmlRepresentation = x.m_xmlRepresentation;
}

HelloWorld::HelloWorldResource::XMLHelloResponse::XMLHelloResponse(XMLHelloResponse &&x)
{
    m_status = x.m_status;
    m_xmlRepresentation = x.m_xmlRepresentation;
}

HelloWorld::HelloWorldResource::XMLHelloResponse& HelloWorld::HelloWorldResource::XMLHelloResponse::operator=(const XMLHelloResponse &x)
{
    m_status = x.m_status;
    m_xmlRepresentation = x.m_xmlRepresentation;
    
    return *this;
}

HelloWorld::HelloWorldResource::XMLHelloResponse& HelloWorld::HelloWorldResource::XMLHelloResponse::operator=(XMLHelloResponse &&x)
{
    m_status = x.m_status;
    m_xmlRepresentation = x.m_xmlRepresentation;
    
    return *this;
}


HelloWorld::HelloWorldResource::HelloResponse::HelloResponse()
{
    m__d = -1000;

}

HelloWorld::HelloWorldResource::HelloResponse::~HelloResponse()
{
}

HelloWorld::HelloWorldResource::HelloResponse::HelloResponse(const HelloResponse &x)
{
    m__d = x.m__d;
    
    switch(m__d)
    {
        case 0:
        m_emptyHelloResponse = x.m_emptyHelloResponse;
        break;
        case 1:
        m_xmlHelloResponse = x.m_xmlHelloResponse;
        break;
    }
}

HelloWorld::HelloWorldResource::HelloResponse::HelloResponse(HelloResponse &&x)
{
    m__d = x.m__d;
    
    switch(m__d)
    {
        case 0:
        m_emptyHelloResponse = std::move(x.m_emptyHelloResponse);break;
        case 1:
        m_xmlHelloResponse = std::move(x.m_xmlHelloResponse);break;
    }
}

HelloWorld::HelloWorldResource::HelloResponse& HelloWorld::HelloWorldResource::HelloResponse::operator=(const HelloResponse &x)
{
    m__d = x.m__d;
    
    switch(m__d)
    {
        case 0:
        m_emptyHelloResponse = x.m_emptyHelloResponse;
        break;
        case 1:
        m_xmlHelloResponse = x.m_xmlHelloResponse;
        break;
    }
    
    return *this;
}

HelloWorld::HelloWorldResource::HelloResponse& HelloWorld::HelloWorldResource::HelloResponse::operator=(HelloResponse &&x)
{
    m__d = x.m__d;
    
    switch(m__d)
    {
        case 0:
        m_emptyHelloResponse = std::move(x.m_emptyHelloResponse);break;
        case 1:
        m_xmlHelloResponse = std::move(x.m_xmlHelloResponse);break;
    }
    
    return *this;
}

void HelloWorld::HelloWorldResource::HelloResponse::_d(int32_t __d)
{
    bool b = false;
    
    switch(m__d)
    {
        case 0:
        switch(__d)
        {
            case 0:
            b = true;
            break;
            default:
            break;
        }
        break;
        case 1:
        switch(__d)
        {
            case 1:
            b = true;
            break;
            default:
            break;
        }
        break;
    }
    
    if(!b) throw BadParamException("Discriminator doesn't correspond with the selected union member");
    
    m__d = __d;
}

int32_t HelloWorld::HelloWorldResource::HelloResponse::_d() const
{
    return m__d;
}

int32_t& HelloWorld::HelloWorldResource::HelloResponse::_d()
{
    return m__d;
}

void HelloWorld::HelloWorldResource::HelloResponse::emptyHelloResponse(const HelloWorld::HelloWorldResource::EmptyHelloResponse &_emptyHelloResponse)
{
    m_emptyHelloResponse = _emptyHelloResponse;
    m__d = 0;
}

void HelloWorld::HelloWorldResource::HelloResponse::emptyHelloResponse(HelloWorld::HelloWorldResource::EmptyHelloResponse &&_emptyHelloResponse)
{
    m_emptyHelloResponse = std::move(_emptyHelloResponse);
    m__d = 0;
}

const HelloWorld::HelloWorldResource::EmptyHelloResponse& HelloWorld::HelloWorldResource::HelloResponse::emptyHelloResponse() const
{
    bool b = false;
        
    switch(m__d)
    {
        case 0:
        b = true;
        break;
        default:
        break;
    }    
    if(!b) throw BadParamException("This member is not been selected");
    
    return m_emptyHelloResponse;
}

HelloWorld::HelloWorldResource::EmptyHelloResponse& HelloWorld::HelloWorldResource::HelloResponse::emptyHelloResponse()
{
    bool b = false;
        
    switch(m__d)
    {
        case 0:
        b = true;
        break;
        default:
        break;
    }    
    if(!b) throw BadParamException("This member is not been selected");
    
    return m_emptyHelloResponse;
}
void HelloWorld::HelloWorldResource::HelloResponse::xmlHelloResponse(const HelloWorld::HelloWorldResource::XMLHelloResponse &_xmlHelloResponse)
{
    m_xmlHelloResponse = _xmlHelloResponse;
    m__d = 1;
}

void HelloWorld::HelloWorldResource::HelloResponse::xmlHelloResponse(HelloWorld::HelloWorldResource::XMLHelloResponse &&_xmlHelloResponse)
{
    m_xmlHelloResponse = std::move(_xmlHelloResponse);
    m__d = 1;
}

const HelloWorld::HelloWorldResource::XMLHelloResponse& HelloWorld::HelloWorldResource::HelloResponse::xmlHelloResponse() const
{
    bool b = false;
        
    switch(m__d)
    {
        case 1:
        b = true;
        break;
        default:
        break;
    }    
    if(!b) throw BadParamException("This member is not been selected");
    
    return m_xmlHelloResponse;
}

HelloWorld::HelloWorldResource::XMLHelloResponse& HelloWorld::HelloWorldResource::HelloResponse::xmlHelloResponse()
{
    bool b = false;
        
    switch(m__d)
    {
        case 1:
        b = true;
        break;
        default:
        break;
    }    
    if(!b) throw BadParamException("This member is not been selected");
    
    return m_xmlHelloResponse;
}




