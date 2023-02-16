#include <stdio.h>
#include <unistd.h>

int FileSystemStatus(char path[]) {
    if (access(path, R_OK) == 0) {
        printf("file can READ \n");
    } else {
        printf("File can`t NON READ \n");
    }
}

int main() {
    char path[] = "../test";
    int inp;
    //
    int fileLookChoose;

    do {
        printf("task fileLooker\n");
        printf("1. Permission check\n");
        printf("2. File lock\n");
        printf("Enter your choice: ");
        scanf("%d", &inp);

        switch (inp) {
            case 1:
                FileSystemStatus(path);
            case 2:
                printf("Lock file status");
                FileSystemStatus(path);
//                if (access())
        }
    } while (inp != 0);
    printf("Good bye \n");
    return 0;
}
