/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file Client.cxx
 * This source file shows a simple example of how to create a proxy for interface Calculator.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "CalculatorProxy.h"
#include "CalculatorRequestReplyPlugin.h"
#include "exceptions/Exceptions.h"

#include <iostream>

class Calculator_additionHandler : public Calculator_additionCallbackHandler
{
    public:

        void addition(/*out*/ DDS_Long addition_ret)
		{
			std::cout << "Addition result: " << addition_ret << std::endl;
		}
        
        void on_exception(const eProsima::RPCDDS::Exception &ex)
		{
			std::cout << "Exception: " << ex.what() << std::endl;
		}
};

class Calculator_subtractionHandler : public Calculator_subtractionCallbackHandler
{
    public:

        void subtraction(/*out*/ DDS_Long subtraction_ret)
		{
			std::cout << "Subtraction result: " << subtraction_ret << std::endl;
		}
        
        void on_exception(const eProsima::RPCDDS::Exception &ex)
		{
			std::cout << "Exception: " << ex.what() << std::endl;
		}
};

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		DDS_Long  value1 = 0;
		DDS_Long  value2 = 0;

		if(sscanf(argv[1], "%d", &value1) == 1)
		{
			if(sscanf(argv[2], "%d", &value2) == 1)
			{
				Calculator_additionHandler addHandler;
				Calculator_subtractionHandler subHandler;
				CalculatorProxy *proxy = NULL;
    
				// Creation of the proxy for interface "Calculator".
				try
				{
					proxy = new CalculatorProxy("CalculatorService");
				}
				catch(eProsima::RPCDDS::InitializeException &ex)
				{
					std::cout << ex.what() << std::endl;
					return -1;
				}

				// Call to remote procedure "addition".
				try
				{
					proxy->addition_async(addHandler, value1, value2);
				}
				catch(eProsima::RPCDDS::Exception &ex)
				{
					std::cout << ex.what() << std::endl;
				}

				try
				{
					proxy->subtraction_async(subHandler, value1, value2);
				}
				catch(eProsima::RPCDDS::Exception &ex)
				{
					std::cout << ex.what() << std::endl;
				}

				// Wait 10 seconds to received the server's replies.
				Sleep(10000);

				delete(proxy);
			}
			else
			{
				std::cout << "Bad parameter (second value)" << std::endl;
			}
		}
		else
		{
			std::cout << "Bad parameter (first value)" << std::endl;
		}
	}
	else
	{
		std::cout << "Usage: CalculatorClient <first value> <second value>" << std::endl;
	}
   
    return 0;
}