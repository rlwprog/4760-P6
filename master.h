typedef struct node {
    struct node *next;
    struct pcb *head; 
} Queue;

typedef struct {
	int seconds;
	int nanosecs;
} clockStruct;

typedef struct {
	int resourcesUsed[20];
} resourceStruct;

typedef struct pcb {
	int pid;
	int requestedResource;
	int totalBlockedTime;
	int blockedBurstSecond;
	int blockedBurstNano;
	resourceStruct *resUsed;
} PCB;

typedef struct {
	long mtype;
	pid_t pid;
	int res;
} mymsg_t;

int sigHandling();

static void endAllProcesses(int signo);
static void childFinished(int signo);

int initPCBStructures();
void tearDown();

Queue *newProcessMember(int pid);
Queue *newBlockedQueueMember(PCB *pcb);
void deleteFromProcessList(int pidToDelete, Queue *ptr);
void printQueue(Queue * ptr);
PCB *newPCB(int pid);
PCB *findPCB(int pid, Queue * ptrHead);

int checkIfTimeToFork();
void setForkTimer();
int deadlockAvoidance(int res);
int bankersAlgorithm(int res, PCB * proc);
void releaseAllResources(resourceStruct * res);