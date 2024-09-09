#include<iostream>
using namespace std;

#define ok 0
#define error -1

class SeqList {
private:
	int* list;
	int maxsize;
	int size;
public:
	SeqList() {
		maxsize = 1000;
		size = 0;
		list = new int[maxsize];
	}
	~SeqList() {
		delete[]list;
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

	void push_back(int i) {
		list[size] = i;
		size++;
	}
	void list_display() {
		for (int i = 0; i < size; i++) {
			cout << list[i] << ' ';
		}
		cout << endl;
	}

	//左移方向为0，右移方向为1
	void lixt_move(int d, int n) {
		//列表复制
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = list[i];
		}
		if (d == 1) {
			//右移
			for (int i = 0; i < size - n; i++) {//不过界
				list[i + n] = temp[i];
			}
			for (int i = 0; i < n; i++) {//过界
				list[i] = temp[size - n + i];
			}


		}
		else {
			//左移
			for (int i = 0; i < size - n; i++) {//没过界
				list[i] = temp[i + n];
			}
			for (int i = 0; i < n; i++) {//过界
				list[size - n + i] = temp[i];
			}
		}
	}
};

int main() {
	int n,a,dir;
	cin >> n;
	SeqList L;
	for (int i = 0; i < n; i++) {
		cin >> a;
		L.push_back(a);
	}
	L.list_display();
	cin >> dir >> a;
	L.lixt_move(dir, a);
	L.list_display();
	cin >> dir >> a;
	L.lixt_move(dir, a);
	L.list_display();
	return 0;
}