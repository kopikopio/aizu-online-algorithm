#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000


struct Process {
    char name[11];
    int exec_time;
};

struct ListElement{
    ListElement* prev;
    ListElement* next;
    int key;
};
ListElement* null_ptr = NULL; // nullポインタ

void printElement(ListElement* element) {
    printf("element->key: %d\n",element->key);
    printf("element->prev: %p\n",element->prev);
    printf("element->next: %p\n",element->next);
}

class DoublyLinekdList
{
private:
    ListElement* m_head;
    ListElement* m_tail;
    int m_num;
public:
    DoublyLinekdList()
    {
        m_head = null_ptr;
        m_tail = null_ptr;
        m_num = 0;
    }
    ~DoublyLinekdList()
    {
        // ! deleteLastを実行するとエラー発生
        ListElement* ptr = m_head;
        while(ptr != null_ptr) {
            ListElement* delete_element = ptr;
            ptr = ptr->prev;
            delete delete_element;
        }
    };
    void print();
    void insert(int x);
    void deleteFirst();
    void deleteLast();
    void delete_key(int x);
};

// 新規要素を先頭要素のnextに追加
void DoublyLinekdList::insert(int x) {

    // 新規要素
    ListElement* insert_element = new ListElement; // ! ポインタ宣言だとBusErrorになった→ポインタ先を設定しないとどこのアドレスを指しているかわからないため
    insert_element->key = x;
    insert_element->prev = m_head;
    insert_element->next = null_ptr;
    // 先頭要素を新規要素に変更
    if (m_head == null_ptr) m_tail = insert_element; // 空の場合に追加要素を最後尾とする
    else m_head->next = insert_element;
    m_head = insert_element;
}

void DoublyLinekdList::print() {
    //* 要素が１つ以上必ず存在すると仮定

    // 新規要素
    ListElement* ptr = m_head;
    while(ptr->prev != null_ptr) {
        printf("%d ",ptr->key);
        ptr = ptr->prev;
    }
    printf("%d\n",ptr->key);
}


void DoublyLinekdList::deleteFirst() {
    //* 要素が１つ以上必ず存在する

    // 削除する要素
    ListElement* delete_element = m_head;
    // データが１件だけだった場合
    if (m_tail == m_head) {
        m_tail = m_tail->next;
        m_head = m_head->next;
        delete delete_element;
        return;
    }
    // 先頭要素を１つ前の要素にする
    m_head = m_head->prev;
    m_head->next = null_ptr;

    // 削除（メモリ開放）
    delete delete_element;

}

void DoublyLinekdList::deleteLast() {
    //* 要素が１つ以上必ず存在する

    // 削除する要素
    ListElement* delete_element = m_tail;
    // データが１件だけだった場合
    if (m_tail == m_head) {
        m_tail = m_tail->next;
        m_head = m_head->next;
        delete delete_element;
        return;
    }
    // 最後尾要素を変更
    m_tail = m_tail->next;
    m_tail->prev = null_ptr;

    // 削除（メモリ開放）
    delete delete_element;

}

void DoublyLinekdList::delete_key(int x) {

    // 削除する要素
    ListElement* delete_element = m_head;
    while(delete_element != null_ptr) {
        if (delete_element->key == x) break;
        delete_element = delete_element->prev;
    }
    // 削除（メモリ開放）
    if(delete_element != null_ptr) {
        if(delete_element == m_head) deleteFirst();
        else if (delete_element == m_tail) deleteLast();
        else {
            ListElement* prev = delete_element->prev;
            prev->next = delete_element->next;
            ListElement* next = delete_element->next;
            next->prev = delete_element->prev;
            delete delete_element;
            
        }
    }

}


int main() {

    int n;

    DoublyLinekdList list;
    // 入力値取得
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        char command[12];
        int key;
        scanf("%s", command);

        if (strcmp(command,"insert") == 0) {
            int key;
            scanf("%d", &key);
            list.insert(key);
        } else if (strcmp(command,"delete") == 0) {
            int key;
            scanf("%d", &key);
            list.delete_key(key);
        } else if (strcmp(command,"deleteFirst") == 0) {
            list.deleteFirst();
        } else if (strcmp(command,"deleteLast") == 0) {
            list.deleteLast();
        }
    }
    // list.delete_key(5);
    // list.insert(4);
    list.print();
}