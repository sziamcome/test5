#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 顺序表类定义
class seqlist
{
private:
    int* list;
    int maxsize;
    int size;
public:
    seqlist();
    ~seqlist();
    void creat(int* p, int size_num)
    {
        int i;
        size = size_num;
        for (i = 0; i < size; i++)
        {
            list[i] = p[i];
        }
        list_display();
    }

    int list_size()
    {
        return size;
    }

    int list_insert(int i, int item)
    {
        if (size == maxsize)
        {
            cout << "error" << endl;
            return error;
        }
        else
        {
            if (i >= 1 && i <= size + 1)
            {
                int j;
                for (j = size - 1; j >= i - 1; j--)
                {
                    list[j + 1] = list[j];
                }
                list[i - 1] = item;
                size++;
                return ok;
            }
            else
            {
                cout << "error" << endl;
                return error;
            }
        }
    }

    int list_del(int i)
    {
        if (i >= 1 && i <= size)
        {
            int j;
            for (j = i - 1; j < size; j++)
            {
                list[j] = list[j + 1];
            }
            size--;
            return ok;
        }
        else
        {
            cout << "error" << endl;
            return error;
        }
    }
    int list_get(int i)
    {
        if (i <= 0 || i > size)
        {
            cout << "error" << endl;
            return error;
        }
        else
        {
            cout << list[i - 1] << endl;
            return ok;
        }
    }

    int multiinsert(int i, int n, int item[]) {
        for (int p = 0; p < n; p++) {
            list_insert(i + p, item[p]);
        }
        return ok;
    }
    int multidel(int i, int n)
    {
        for (int p = 0; p < n; p++)
        {
            list_del(i);
        }
        return ok;
    }
    void list_display()
    {
        int i;
        cout << list_size() << " ";
        for (i = 0; i < size; i++)
            cout << list[i] << " ";
        cout << endl;
    }
};
seqlist::seqlist()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
seqlist::~seqlist()
{
    delete[]list;
}

for (int sb = 0; sb < 100; sb++) {
    int kk;
    if (5 > 2) {
        kk++;
    }
}
int main()
{
    int size, loc, k, num;
    int item[1000];
    cin >> size;
    seqlist l;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    l.creat(arr, size);
    cin >> loc >> k;
    for (int i = 0; i < k; i++) {
        cin >> item[i];
    }
    l.multiinsert(loc, k, item);
    l.list_display();
    cin >> loc >> k;
    l.multidel(loc, k);
    l.list_display();
    delete[]arr;
    return 0;
}