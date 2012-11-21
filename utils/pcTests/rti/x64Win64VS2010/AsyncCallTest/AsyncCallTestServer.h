/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file AsyncCallTestServer.h
 * This header file contains the declaration of the server for interface AsyncCallTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _AsyncCallTestSKELETON_H_
#define _AsyncCallTestSKELETON_H_

#include "server/Server.h"
#include "AsyncCallTestServerImpl.h"
#include "AsyncCallTestRequestReplyUtils.h"

/**
 * \brief This class implements a specific server for the defined interface by user.
 */
class AsyncCallTestServer : public eProsima::RPCDDS::Server
{
    public:
    
        /**
         * \brief Default constructor. The server will use the default eProsima::RPCDDS::UDPTransport.
         *
         * \param serviceName The service's name that proxies will use to connect with the server.
         * \param strategy Strategy used by server to work with new requests.
         *        This class doesn't delete this object in its destructor. Cannot be NULL.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0.
         * \exception eProsima::RPCDDS::InitializeException This exception is thrown when the initialization was wrong.
         */
        AsyncCallTestServer(std::string serviceName, eProsima::RPCDDS::ServerStrategy *strategy,
            int domainId = 0);

        /**
         * \brief This constructor sets the transport that will be used by the server.
         *
         * \param serviceName The service's name that proxies will use to connect with the server.
         * \param strategy Strategy used by server to work with new requests.
         *        This class doesn't delete this object in its destructor. Cannot be NULL.
         * \param transport The network transport that server has to use.
         *        This transport's object is not deleted by this class in its destrcutor. Cannot be NULL.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0.
         * \exception eProsima::RPCDDS::InitializeException This exception is thrown when the initialization was wrong.
         */
        AsyncCallTestServer(std::string serviceName, eProsima::RPCDDS::ServerStrategy *strategy, eProsima::RPCDDS::Transport *transport,
            int domainId = 0);

        /// \brief The default destructor.
        virtual ~AsyncCallTestServer();

        static void getLong(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service);
        static void getBoolean(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service);
        static void getString(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service);
        static void duplicate(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service);
        
     private:
        /**
         * \brief This function creates all RPC endpoints for each remote procedure.
         */
        void createRPCs();
        
        /// \brief Pointer to the server's servant implemented by the user.
        AsyncCallTestServerImpl *_impl;
};

#endif // _AsyncCallTestSKELETON_H_