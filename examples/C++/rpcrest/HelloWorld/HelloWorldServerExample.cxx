/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcrest_LICENSE file included in this rpcrest distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldServerExample.cxx
 * This source file shows a simple example of how to create a server for an interface.
 *
 * This file was generated by the tool rpcrestgen.
 */

#include "HelloWorldServer.h"
#include "rpcrest/strategies/ThreadPoolStrategy.h"
#include "HelloWorldRESTProtocol.h"
#include "rpcrest/transports/HttpServerTransport.h"
#include "rpcrest/exceptions/Exceptions.h"
#include "rpcrest/utils/Utilities.h"
#include "HelloWorldServerImplExample.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace eprosima::rpc::exception;
using namespace eprosima::rpc::strategy;
using namespace eprosima::rpc::transport;
using namespace eprosima::rpc::protocol::rest;

int main(int argc, char **argv)
{
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    HelloWorldProtocol *protocol = NULL;
    HttpServerTransport *transport = NULL;
    HelloWorld::HelloWorldResourceServer *server = NULL;
    HelloWorldResourceServerImplExample servant;
    
    // Create and initialize the server for interface "HelloWorld::HelloWorldResource".
    try
    {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new HelloWorldProtocol();
        transport = new HttpServerTransport("127.0.0.1:8080");
        server = new HelloWorld::HelloWorldResourceServer(*pool, *transport, *protocol, servant);
        server->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    while(1)
    {
        eprosima::rpc::sleep(10000);
    }
    
    // Stop and delete the server.
    server->stop();
    delete server;
    delete protocol;
    delete transport;
    delete pool;
    
    return 0;
}



