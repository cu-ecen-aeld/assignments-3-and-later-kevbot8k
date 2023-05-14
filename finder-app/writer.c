#include <stdio.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    openlog(NULL, 0, LOG_USER);

    if (argc < 2) {
        syslog(LOG_ERR, "Invalid Number of arguments: %d", argc);
        return 1;
    }

    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, S_IWGRP | S_IROTH | S_IWUSR | S_IRUSR);
    if (fd == -1) {
        syslog(LOG_ERR, "File failed to open");
        return 1;
    }
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    ssize_t bytesWritten = write(fd, argv[2], strlen(argv[2]));
    if (bytesWritten == -1) {
        syslog(LOG_ERR, "Failed to write to file");
        return 1;
    }

    int error_code = close(fd);
    if (error_code != 0) {
	syslog(LOG_ERR, "Failed to close file");
    }
    return 0;
}
