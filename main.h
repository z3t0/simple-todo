// Defines
#define NAME_LENGTH 100
#define DESCRIPTION_LENGTH 1000
#define TASK_LIMIT 100
#define MAX_FILE_LENGTH 10000

// Structures
struct Task {
  char name[NAME_LENGTH];
  char description[DESCRIPTION_LENGTH];
};

struct Database {
  struct Task tasks[TASK_LIMIT];
};

// Function prototypes
int read_file (char *path, char *buffer);
