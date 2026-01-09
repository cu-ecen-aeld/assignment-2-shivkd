#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    //set up syslog system
    openlog("writer", LOG_PID, LOG_USER);
    //check the number of arguments
    if( argc !=3){
        syslog(LOG_ERR, "INVALID NUMBER OF ARGUEMNTS");
        fprintf(stderr, "USAGE ERROR");
        closelog();
        exit(1);

    }
    //define the arguments and their names
    const char *writefile = argv[1];
    const char *writestr = argv[2];
    //Debug log to show where we are writing to 
    syslog(LOG_DEBUG,"Writing %s to %s", writestr, writefile);
    //open file for writing
    int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1){
        syslog(LOG_ERR, "COULD NOT OPEN FILE");
        fprintf(stderr, "File opening error");
        closelog();
        exit(1);
    }
    size_t length = strlen(writestr);
    ssize_t written = write(fd, writestr, length);
    if(written == -1){
        syslog(LOG_ERR, "Error writing to file");
        fprintf(stderr, "Writing to file ERROR");
        close(fd);
        closelog();
        exit(1);
    }
    if(close(fd)== -1){
        syslog(LOG_ERR, "Error closing file");
        fprintf(stderr, "File closing error");
        closelog();
        exit(1);
    }
    closelog();
    return 0;

        
}
