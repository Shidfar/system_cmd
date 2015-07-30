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
        {
            result += " * ";
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

int main()
{
//<<<<<<< HEAD

//    sleep 1; xset dpms force off turns off the screen
    int x;
    x = 2;
    char * commm = "exit";
//    if(x == 1)
//        commm = (char *) "sensors";
//    if(x == 2)
//        commm = (char *) "sudo hddtemp /dev/sda";

    string res1, res;
    while(true)
    {

        commm = (char *) "hddtemp /dev/sda";
        res = exec(commm);
        commm = (char *) "hddtemp /dev/sda1";
        res += exec(commm);
        commm = (char *) "hddtemp /dev/sda2";
        res += exec(commm);
        commm = (char *) "hddtemp /dev/sda5";
        res += exec(commm);

        commm = (char *) "sensors";
        res1 = exec(commm);
        system("clear");
        cout<<" ***********************************************************\n";
        cout<<res;
        cout<<" * \n";
        cout<<res1<<endl;
        if(x == -1)
            break;
        this_thread::sleep_for(chrono::seconds(2));
    }
//=======
//    string res = exec((char *) "ifconfig | perl -nle'/dr:(\\S+)/ && print $1'");
//    cout<<" > Internal address:" <<endl;
//    cout<<res<<endl;
//    cout<<" > External address:" <<endl;
//    res = exec((char *) "dig +short myip.opendns.com @resolver1.opendns.com");
//    cout<<res<<endl;

//>>>>>>> 596626a10d41b6443c9a3e61fda569b5135f699e
    return 0;
}
