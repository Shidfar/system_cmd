#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
string exec(char* cmd)
{
//    Replace popen and pclose with _popen and _pclose for Windows.
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";

    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

int main()
{
<<<<<<< HEAD

//    sleep 1; xset dpms force off turns off the screen
    string res = exec("ifconfig");
    cout<<" *********************** " <<endl;
    cout<<" >> " <<res<<endl;
    cout<<" *********************** " <<endl;
=======
    string res = exec((char *) "ifconfig | perl -nle'/dr:(\\S+)/ && print $1'");
    cout<<" > Internal address:" <<endl;
    cout<<res<<endl;
    cout<<" > External address:" <<endl;
    res = exec((char *) "dig +short myip.opendns.com @resolver1.opendns.com");
    cout<<res<<endl;

>>>>>>> 596626a10d41b6443c9a3e61fda569b5135f699e
    return 0;
}
