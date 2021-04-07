#include <iostream>

using namespace std;

struct DoubleList //описание узла списка
{
    int data; //информационное поле
    struct DoubleList *next; //указатель на следующий элемент
    struct DoubleList *prev; //указатель на предыдущий элемент
};
   DoubleList *head; //указатель на первый элемент списка

//добавление элемента
struct DoubleList * AddList(int value, int position)
{
struct DoubleList* node = new DoubleList; //создание нового элемента
node->data = value; //присвоение элементу значения
if (head == NULL) //если список пуст
{
node->next = node; //установка указателя next
node->prev = node; //установка указателя prev
head = node; //определяется голова списка
}
else
{
struct DoubleList* p = head;
for (int i = position; i > 1; i--)
p = p->next;
p->prev->next = node;
node->prev = p->prev;
node->next = p;
p->prev = node;
}

cout << "\nЭлемент добавлен...\n\n";

}
int GetCount()
{
    int c = 1;
    if (head==nullptr) {return 0;}
    struct DoubleList *tmp = head->next;
    if (tmp->next==head) {return 1;}

    while (tmp != head)
    {
        tmp = tmp->next;
        c++;
    }

    return c;
}


//удаление элемента
struct DoubleList * DeleteList(int position){
    if (position < 0) {position = 0;}
    if (position > GetCount()) {position = GetCount();}
if (head==NULL) { cout<<"\nСписок пуст\n\n"; return 0; }
if (head==head->next) {head=NULL;}
else
{
struct DoubleList *a=head;
for (int i=0; i<position; i++) a=a->next;
if (a==head) head=a->next;
a->prev->next=a->next;
a->next->prev=a->prev;
delete a;
}
cout<<"\nЭлемент удален...\n\n";
}

//вывод элементов списка
struct DoubleList * PrintList()
{
if (head==NULL) cout << "\nСписок пуст\n\n";
else
{
struct DoubleList *a=head;
cout<<"\nЭлементы списка: ";
do
{
    cout<<a->data<<" ";
    a=a->next;
    } while(a!=head); cout<<"\n\n";
    }
}

int main()
{
    setlocale(0, "");
    int value, position, x;
    AddList(1, 0);
    AddList(2, 0);
    AddList(3, 0);
    AddList(4, 0);
    AddList(5, 0);
    AddList(6, 0);
    do
    {
    cout << "1. Добавить элемент" << endl;
    cout << "2. Удалить элемент" << endl;
    cout << "3. Вывести список" << endl;
    cout << "0. Выйти" << endl;
    cout << "\nНомер операции > "; cin >> x;
    switch (x)
    {
    case 1:
    cout<<"Значение > "; cin>>value;

    AddList(value, position); break;
    case 2:
    cout<<"Позиция > "; cin>>position;
    DeleteList(position); break;
    case 3: PrintList(); break;
    }
    } while (x!=0);
    return 0;
}

