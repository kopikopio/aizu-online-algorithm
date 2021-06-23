#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NUM 100000

struct Process {
    char name[11];
    int exec_time;
};

class ProcessQueue
{
private:
    int m_size;
    int m_head;
    int m_tail;
    int m_num;
    Process* m_processes;
public:
    ProcessQueue(int size):
        m_size(size),
        m_head(0),
        m_tail(0),
        m_num(0)
    {
        m_processes = new Process[m_size]; // ? newで確保した領域のポインタを渡してくれる？
    }
    ~ProcessQueue();
    bool isFull();
    bool isEmpty();
    void enQueue(Process process);
    Process deQueue();
    void print();
};

bool ProcessQueue::isEmpty() {
    return m_num == 0 ? true : false;
}
void ProcessQueue::enQueue(Process process)
{
    m_processes[m_tail] = process;
    m_tail++;
    if(m_tail >= m_size) m_tail = 0;
    m_num++;
}
Process ProcessQueue::deQueue()
{
    Process process = m_processes[m_head];
    m_head++;
    if(m_head >= m_size) m_head = 0;
    m_num--;
    return process;

}

ProcessQueue::~ProcessQueue()
{
    delete[] m_processes;
}

int main() {

    int n;
    int quantum;

    // 入力値取得
    scanf("%d", &n);
    scanf("%d", &quantum);
    
    ProcessQueue queue(n);
    for (int i=0; i<n; i++) {
        char process_name[11];
        int exec_time;
        scanf("%s", process_name);
        scanf("%d", &exec_time);
        Process process;
        strcpy(process.name, process_name);
        process.exec_time = exec_time;
        queue.enQueue(process);
    }

    int amount_time = 0;
    while(!queue.isEmpty()) {
        Process process = queue.deQueue();
        if (process.exec_time > quantum) {
            process.exec_time = process.exec_time - quantum;
            amount_time += quantum;
            queue.enQueue(process);
        }
        else {
            amount_time += process.exec_time;
            printf("%s %d\n", process.name, amount_time);
        }
    }
}