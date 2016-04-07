#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

// read a file.
void yancycp(char *src_path, char *des_path){
    // to know the file length
	struct stat fileinfo;
	unsigned long file_len;
	if (stat(src_path, &fileinfo)<0){
		perror("stat error!");
		exit(EXIT_FAILURE);
	}
	else{
		file_len = fileinfo.st_size;
	}
	//  to read the file
    char *read_buf;
	read_buf = (char *)malloc(file_len);
    int fd = open(src_path, O_RDONLY);   //  open file
    if (fd == -1){
        perror("open error");
        exit(EXIT_FAILURE);
    }
	ssize_t nread = read(fd, (void *)read_buf, file_len);   //  read file
	if (nread == -1){
        perror("read");
        exit(EXIT_FAILURE);
	}
    close(fd);
    //printf("%s", read_buf);

    fd = open(des_path, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if (fd == -1){
        perror("open error");
        exit(EXIT_FAILURE);
    }
    ssize_t nwrite = write(fd, read_buf, file_len);
    if (nwrite < file_len){
        perror("write");
        exit(EXIT_FAILURE);
    }
    close(fd);
}
