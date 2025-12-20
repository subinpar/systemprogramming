#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

static void print_time(time_t t){
	struct tm *tm=localtime(&t);
	char buf[64];
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);
	printf("%s\n", buf);
}

static const char* file_type(mode_t mode){
	if(S_ISREG(mode)) return "Regular file";
	if(S_ISDIR(mode)) return "Directory";
	if(S_ISLNK(mode)) return "Symbolic link";
	if(S_ISCHR(mode)) return "Character device";
	if(S_ISBLK(mode)) return "Block device";
	if(S_ISFIFO(mode)) return "FIFO (pipe)";
	if(S_ISSOCK(mode)) return "Socket";
	return "Unknown";
}

static void make_perm_string(mode_t mode, char perm[10]){
	perm[0]=(mode&S_IRUSR)?'r':'-';
	perm[1]=(mode&S_IWUSR)?'w':'-';
	perm[2]=(mode&S_IXUSR)?'x':'-';
	
	perm[3]=(mode&S_IRGRP)?'r':'-';
	perm[4]=(mode&S_IWGRP)?'w':'-';
	perm[5]=(mode&S_IXGRP)?'x':'-';
	
	perm[6]=(mode&S_IROTH)?'r':'-';
	perm[7]=(mode&S_IWOTH)?'w':'-';
	perm[8]=(mode&S_IXOTH)?'x':'-';
	
	perm[9]='\0';
}
int main(int argc, char *argv[]){
	struct stat st;
	
	if(argc!=2){
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return 1;
	}
	if(stat(argv[1], &st)==-1){
		perror("stat");
		return 1;
	}
	
	char perm[10];
	make_perm_string(st.st_mode,perm);
	
	printf("File name: %s\n", argv[1]);
	printf("File type: %s\n", file_type(st.st_mode));
	printf("File permissions: %s\n", perm);
	printf("Number of links: %lu\n", (unsigned long)st.st_nlink);
	printf("UID: %u\n", st.st_uid);
	printf("GID: %u\n", st.st_gid);
	printf("File size: %lld bytes\n", (long long)st.st_size);
	
	printf("Last access time (atime): ");
	print_time(st.st_atime);
					 	
	printf("Last modification time (mtime): ");
	print_time(st.st_mtime);
	
	printf("Last status change time (ctime): ");
	print_time(st.st_ctime);
	
	return 0;
}					 	
