// http://www.linuxquestions.org/questions/programming-9/c-list-files-in-directory-379323/

//#include <sys/types.h>
#include <dirent.h>
//#include <errno.h>
//#include <vector>
#include <string>
#include <iostream>

using namespace std;



/*function... might want it in some class?*/
//int getdir (string dir, vector<string> &files)
int getdir (string dir)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        //cout << "Error(" << errno << ") opening " << dir << endl;
        cout << "Error - opening " << dir << endl;
        //return errno;
        return 0;
    }

    while ((dirp = readdir(dp)) != NULL) {
        //files.push_back(string(dirp->d_name));
        cout << string(dirp->d_name) << "\n";
    }
    closedir(dp);
    return 0;
}

int main()
{
    string dir = string(".");
    //vector<string> files = vector<string>();

    //getdir(dir,files);
    getdir(dir);

    //for (unsigned int i = 0;i < files.size();i++) {
    //    cout << files[i] << endl;
    //}
    return 0;
}