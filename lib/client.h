
#define NICK_SIZE 20

typedef struct {
	char nickname[NICK_SIZE];
	int fd; // file descriptor
} client_t;
