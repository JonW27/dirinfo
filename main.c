#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void openDir(char * dir){

    // get name
    DIR * d;
    d = opendir(dir);
    printf("Statistics for directory: '%s'\n", dir);

    // get size
    struct stat buf;
    stat(dir, &buf);
    printf("Total Directory Size: %jd Bytes\n", (intmax_t)buf.st_size); 
    // https://stackoverflow.com/questions/586928/how-should-i-print-types-like-off-t-and-size-t 
    //and http://wiki.duktape.org/ApiCTypes.html

    // check if directory
    printf("Directories:\n");
    struct dirent *entry = readdir(d);
    while(entry){
        if(entry->d_type == DT_DIR){
            printf("\t%s\n", entry->d_name);
        }
        entry = readdir(d);
    }
    printf("\n");

    // list files
    rewinddir(d);
    printf("Regular Files:\n");
    entry= readdir(d);
    while(entry){
        if(entry->d_type != DT_DIR){
            printf("\t%s\n", entry->d_name);
        }
        entry = readdir(d);
    }
    printf("\n===============================\n\n");

    // close dir
    closedir(d);

}

int main(){
    openDir(".");
    openDir("testdata");
    openDir("jonathan");
    openDir("dw's secret lair");
    return 0;
}
