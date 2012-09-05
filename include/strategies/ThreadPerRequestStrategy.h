#ifndef _STRATEGIES_THREADPERREQUESTSTRATEGY_H_
#define _STRATEGIES_THREADPERREQUESTSTRATEGY_H_

#include "server/ServerStrategy.h"
#include "utils/ddsrpc.h"

namespace eProsima
{
    namespace DDSRPC
    {
        class ThreadPerRequestStrategyJob;

        class DDSRPC_WIN32_DLL_API ThreadPerRequestStrategy : public ServerStrategy
        {
            public:

                ThreadPerRequestStrategy();

                virtual void schedule(fExecFunction execFunction, void *data, Server *server, ServerRPC *service);

            private:

        };
    } // namespace DDSRPC
} //namespace eProsima

#endif // _STRATEGIES_THREADPERREQUESTSTRATEGY_H_
