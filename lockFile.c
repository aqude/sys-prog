#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/home/aqude/CLionProjects/fileLock/text", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    struct flock fl = {F_RDLCK, SEEK_SET, 0, 0, 0};
    int result = fcntl(fd, F_SETLK, &fl);
    if (result == -1) {
        perror("Failed to lock file");
        return 1;
    }

    // Файл заблокирован для чтения, выполнение кода продолжится здесь

    fl.l_type = F_UNLCK;
    result = fcntl(fd, F_SETLK, &fl);
    if (result == -1) {
        perror("Failed to unlock file");
        return 1;
    }

    close(fd);
    return 0;
}
