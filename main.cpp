#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <time.h>
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
    string res = exec("ifconfig");
    cout<<" *********************** " <<endl;
    cout<<" >> " <<res<<endl;
    cout<<" *********************** " <<endl;
    return 0;
}
