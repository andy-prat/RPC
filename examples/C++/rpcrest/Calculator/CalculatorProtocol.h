/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcrest_LICENSE file included in this rpcrest distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorProtocol.h
 * This header file contains the declaration of the interface for all protocols.
 *
 * This file was generated by the tool rpcrestgen.
 */

#ifndef _Calculator_PROTOCOL_H_
#define _Calculator_PROTOCOL_H_

#include "rpcrest/protocols/Protocol.h"
#include "Calculator.h"
#include "CalculatorServerImpl.h"

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            /*!
             * @brief Protocol base class for the specific application
             * @ingroup CALCULATOR
             */
            class RPCUSERDllExport CalculatorProtocol : public Protocol
            {
                public:
                
                   /*!
                    * @brief This method sets the transport for the communications. It has to be implemented by the children classes.
                    * @param transport Transport to use.
                    * @return True if the assignment is successful, false otherwise
                    */
                    virtual bool setTransport(eprosima::rpc::transport::Transport &transport) = 0;
                    
                        /*!
                         * @brief In some protocols this function activates needed entities to use an interface.
                         * @param interfaceName Interface name.
                         * @return Whether the activation works successfully.
                         */
                    virtual bool activateInterface(const char* interfaceName) = 0;
                    

                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkCalculator_addResourceImpl(Calculator::addResourceServerImpl &impl)
                                        {
                                            _Calculator_addResource_impl = &impl;
                                        }
                                        

                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkCalculator_substractResourceImpl(Calculator::substractResourceServerImpl &impl)
                                        {
                                            _Calculator_substractResource_impl = &impl;
                                        }
                                        

                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkCalculator_multiplyResourceImpl(Calculator::multiplyResourceServerImpl &impl)
                                        {
                                            _Calculator_multiplyResource_impl = &impl;
                                        }
                                        

                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkCalculator_divideResourceImpl(Calculator::divideResourceServerImpl &impl)
                                        {
                                            _Calculator_divideResource_impl = &impl;
                                        }
                                        
                             



                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation add.
                     *        It has to be implemented by the child classes.
                     */
                    virtual Calculator::addResource::AddResponse Calculator_addResource_add(/*in*/ int32_t a, /*in*/ int32_t b) = 0;





                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation substract.
                     *        It has to be implemented by the child classes.
                     */
                    virtual Calculator::substractResource::SubstractResponse Calculator_substractResource_substract(/*in*/ int32_t a, /*in*/ int32_t b) = 0;





                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation multiply.
                     *        It has to be implemented by the child classes.
                     */
                    virtual Calculator::multiplyResource::MultiplyResponse Calculator_multiplyResource_multiply(/*in*/ int32_t a, /*in*/ int32_t b) = 0;





                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation divide.
                     *        It has to be implemented by the child classes.
                     */
                    virtual Calculator::divideResource::DivideResponse Calculator_divideResource_divide(/*in*/ int32_t a, /*in*/ int32_t b) = 0;



                    
                protected:
                
                    CalculatorProtocol() : Protocol()
                                         
                                        , _Calculator_addResource_impl(NULL)
                                        
                                         
                                        , _Calculator_substractResource_impl(NULL)
                                        
                                         
                                        , _Calculator_multiplyResource_impl(NULL)
                                        
                                         
                                        , _Calculator_divideResource_impl(NULL)
                                        
                    {}
                    
                    virtual ~CalculatorProtocol(){}
                
                	                     
                	                    Calculator::addResourceServerImpl *_Calculator_addResource_impl;
                	                    
                	                     
                	                    Calculator::substractResourceServerImpl *_Calculator_substractResource_impl;
                	                    
                	                     
                	                    Calculator::multiplyResourceServerImpl *_Calculator_multiplyResource_impl;
                	                    
                	                     
                	                    Calculator::divideResourceServerImpl *_Calculator_divideResource_impl;
                	                    
                    
            };
        } // namespace protocol
    } // namespace rpc
} // namespace eprosima

#endif // _Calculator_PROTOCOL_H_
