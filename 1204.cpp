#include <iostream>
#include <string.h>

using namespace std;

class charList
{
public:
	char *data;
	int len;
	charList() {
		data = new char[2001];
		data[0] = '\0';
		len = 0;
	}
	~charList() {
		delete[] data;
	}
	void set(char * str) {
		len = strlen(str);
		for (int i = 0; i < len; i++)
			data[i] = str[i];
		data[len] = '\0';
	}
	void insert(int pos, char *str)
	{
		if (pos > len || pos < 0)
		{
			cout << "Error!" << endl;
			return;
		}
		int slen = strlen(str);
		for (int i = len - 1; i >= pos; i--)
			data[i + slen] = data[i];
		for (int i = 0; i < slen; i++)
			data[i + pos] = str[i];
		len += slen;
		data[len] = '\0';
		return;
	}
	void del(int pos, int num)
	{
		if ((pos + num - 1) > len || pos < 0)
		{
			cout << "Error!" << endl;
			return;
		}
		for (int i = pos; i < len - num; i++)
		{
			data[i] = data[i + num];
		}
		len -= num;
		data[len] = '\0';
		return;

	}
};


int main() {
	charList *text = new charList[101];
	char *tmp = new char[2001];
	int lines = 0;
	while (true) {
		cin.getline(tmp, 2000);
		if (strcmp(tmp, "******") == 0) break;
		text[lines++].set(tmp);
	}
	char *cm = new char[10];
	int a, b,num;
	char *str = new char[2005];
	while (1) {
		cin >> cm;
		if (cm[0] == 'q') {
			for (int i = 0; i < lines; i++)
				cout << text[i].data << endl;
			break;
		}
		if (cm[0] == 'i') {
			cin >> a >> b;
			cin.get();
			cin.getline(str, 2005);
			if (a <= 0 || a > lines) {
				cout << "Error!" << endl;
				continue;
			}
			text[a - 1].insert(b - 1, str);
		}
		if (cm[0] == 'd') {
			cin >> a >> b >> num;
			if (a <= 0 || a > lines) {
				cout << "Error!" << endl;
				continue;
			}
			text[a - 1].del(b - 1, num);
		}
		if (cm[0] == 'l') {
			cin >> a >> b;
			if (a <= 0 || b > lines || a > b) {
				cout << "Error!" << endl;
				continue;
			}
			for (int i = a; i <= b; i++)
				cout << text[i - 1].data << endl;
		}
	}
	return 0;
}