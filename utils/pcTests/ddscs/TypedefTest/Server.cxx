/** 
 * Generated by DDSCS    *
 * Simplest server main  *
 */

#include "TypedefTestServer.h"

int main()
{
    int returnedValue = 0;
    int domainId = 0;
    unsigned int threadPoolSize = 5;
    TypedefTestServer *server = new TypedefTestServer(domainId, threadPoolSize,
"TypedefTest_Library",
"TypedefTest_Profile");
    server->executeServer();

    delete server;
}