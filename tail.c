#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void tail (int fd, char *fileName, int linesToDisplay, int shouldShowFileName, int stdin) {
    char buf [1024];
    int charRead;
    int totalLineCount = 0;
    if (stdin == 1) {
        int temp = open ("temporary", O_CREATE | O_RDWR);
        while ((charRead = read(fd, buf, sizeof(buf))) > 0) {
            write(temp, buf, charRead);
        }
        fileName = "temporary";
    }
    int fd2 = open(fileName, 0);
    while ((charRead = read(fd2, buf, sizeof(buf))) > 0)
    {
        for (int i = 0; i < charRead; i++) {
            if (buf[i] == '\n') {
                totalLineCount++;
            }
        }
    }
    close(fd2);
    fd2 = open(fileName, 0);
    int currentLineCount = 0;
    int isPreviousNewLine = 0;
    while((charRead = read(fd2, buf, sizeof(buf))) > 0) {
        for (int i = 0; i< charRead; i++) {
            if (currentLineCount >= (totalLineCount - linesToDisplay))
            {
                if (isPreviousNewLine == 1 && shouldShowFileName == 1) {
                    printf(1, "%s: ", fileName);
                }
                printf(1, "%c",buf[i]);
            }
            else if (totalLineCount < linesToDisplay)
            {
                if (isPreviousNewLine == 1 && shouldShowFileName == 1) {
                    printf(1, "%s: ", fileName);
                }
                printf(1, "%c",buf[i]);
            }
            else if (buf[i] == '\n')
            {
                currentLineCount++;
            }

            if (buf[i] == '\n') {
                isPreviousNewLine = 1;
            } else {
                isPreviousNewLine = 0;
            }
        }
    }
    close(fd2);
    if(fd == 0){
    	unlink(fileName);
    }
}

int main(int argc, char *argv[]) {
    int lenToPrint = 10;
    int fd = 0;
    char *fileName = "";
    int shouldShowFileName = 0;
    int lineLengthArgCount = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp("-n", argv[i]) == 0) {
            if (lineLengthArgCount == 1) {
                printf(1, "tailf: only one argument for line length can be passed in the input\n");
            }
            lenToPrint = atoi(argv[++i]);
            lineLengthArgCount = 2;
        }
    }

    if (argc - lineLengthArgCount - 1 > 1) {
        shouldShowFileName = 1;
    }

    if (argc == 1) {
 
        tail(fd, fileName, lenToPrint, shouldShowFileName, 1);
    } else if (argc > 1) {
        for (int i = 1+lineLengthArgCount; i < argc; i++) {
            if (*argv[i] == '-') continue;
            if ((fd = open(argv[i], 0)) < 0) {
                printf(1, "tail: cannot open the file %s \n", argv[i]);
                exit();
            }
            tail(1, argv[i], lenToPrint, shouldShowFileName, 0);
            close(fd);
        }
    }

    exit();
}
