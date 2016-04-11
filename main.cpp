#include "cepollclient.h"
#include <stdlib.h>
#include <stdio.h>
int my_atoi(char *str)
{
    int ans = 0;
    int i = 0;
    while(str[i]) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        ans = ans * 10 + (str[i] - '0');
        i++;
    }
    return ans;
}
int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Error, eg:./%s <host> <port> <connection number>\n", argv[0]);
        exit(1);
    } 
    CEpollClient *pCEpollClient = new CEpollClient(my_atoi(argv[3]), argv[1], my_atoi(argv[2]));
    if(NULL == pCEpollClient)
    {
        cout<<"[epollclient error]:main init"<<"Init CEpollClient fail"<<endl;
    }

    pCEpollClient->RunFun();

    if(NULL != pCEpollClient)
    {
        delete pCEpollClient;
        pCEpollClient = NULL;
    }

    return 0;
}
