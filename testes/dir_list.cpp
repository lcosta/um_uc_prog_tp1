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
void getdir (string dir)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error - opening " << dir << endl;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if(strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0){
          cout << string(dirp->d_name) << "\n";
        }
    }
    closedir(dp);
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