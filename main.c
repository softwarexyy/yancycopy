#include "yancycopy.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("main argument error\n");
        exit(EXIT_FAILURE);
    }
    yancycp(argv[1], argv[2]);
    return 0;
}
