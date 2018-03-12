#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
    int inputFile, outputFile,fileIn;
    char buffer[8192];
    inputFile = open (argv [1], O_RDONLY);
    outputFile = open(argv[2], O_WRONLY | O_CREAT, 0777);
    while((fileIn = read (inputFile, &buffer, 8192)) > 0)
        write (outputFile, &buffer, (ssize_t) fileIn);
    close(inputFile);
    close(outputFile);
    return 0;
}