#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 10;

class Protocol
{
public:
	virtual void send(char* buf, int len) = 0;
};

class BinaryProtocol : public Protocol
{
public:
	void send(char* buf, int len)
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
		{
			bitset<8> x(buf[i]);
			cout << x << ' ';
		}
	}
};

class HexProtocol : public Protocol
{
public:
	void send(char* buf, int len)
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
			cout << "0x" << hex << (int)(buf[i] & 0xff) << ' ';
	}
};


void sendAll(Protocol** p, int number_of_prorocols)
{
	char x[SIZE];
	cin >> x;

	for (int i = 0; i < number_of_prorocols; i++)
	{
		cout << "Protocol" << i + 1 << ": ";
		p[i]->send(x, SIZE);
		cout << endl;
	}
}

void readFile()
{
	string fn, line;

	cout << "Введите имя файла: ";
	cin >> fn;

	fstream file;
	file.open(fn);
	if (file.is_open() != true)
	{
		cout << "Ошибка!\n" << endl;
		return;
	}

	string protocol_queue = "";
	int nop = 0;
	while (file >> line)
	{
		protocol_queue.push_back(line[0]);
		nop++;
	}

	file.close();

	Protocol** p = new Protocol * [nop];
	for (int i = 0; i < protocol_queue.size(); i++)
		if (protocol_queue[i] == 'H') p[i] = new HexProtocol;
		else p[i] = new BinaryProtocol;
	sendAll(p, nop);
	delete[] p;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char x[SIZE];
	cin >> x;
	BinaryProtocol a;
	a.send(x, SIZE);
	cout << endl << string(60, '_') << endl;
	HexProtocol b;
	b.send(x, SIZE);
	cout << endl << endl;
	readFile();
}