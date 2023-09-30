#include <iostream>
#include <vector>
using namespace std;

class CircularBuffer {
	vector <int> cBuffer;
	int CapacityBuffer;
public:
	CircularBuffer(int n) {
		cBuffer.reserve(n);
		CapacityBuffer = n;
	}
	CircularBuffer() {
		cBuffer.reserve(10);
		CapacityBuffer = 10;
	}
	~CircularBuffer() {
		cout << "\nBuffer deleted\n";
	}
	void DisplayBuffer() {
		for (auto now : cBuffer) {
			cout << now << " ";
		}
		cout << endl;
	}

	void sizeBuffer() {
		cout << "capacity: " << cBuffer.capacity() << endl;
		cout << "size: " << cBuffer.size() << endl;
	}

	void pushBack(int number) {
		if (cBuffer.size() < CapacityBuffer) {
			cBuffer.push_back(number);
		} else {
			for (int i = 0; i < CapacityBuffer - 1; ++i) {
				cBuffer[i] = cBuffer[i + 1];
			}
			cBuffer[CapacityBuffer - 1] = number;
		}
	}

	void pushFront(int number) {
		if (cBuffer.size() < CapacityBuffer) {
			cBuffer.insert(cBuffer.begin(), number);
		} else {
			cBuffer.pop_back();
			cBuffer.insert(cBuffer.begin(), number);
		}
	}

	void popBack() {
		if (cBuffer.empty()) {
			cout << "Buffer is empty\n";
		} else {
			cBuffer.pop_back();
		}
	}

	void popFront() {
		if (cBuffer.empty()) {
			cout << "Buffer is empty\n";
		}
		else {
			cBuffer.erase(cBuffer.begin());
		}
	}
};

int main() {
    cout << "Create\n";
	CircularBuffer exampleCircularBuffer(8);
	exampleCircularBuffer.pushBack(6);
	// 6
	exampleCircularBuffer.DisplayBuffer();
	
	cout << "Add back\n";
	exampleCircularBuffer.pushBack(7);
	exampleCircularBuffer.pushBack(8);	
	// 6 7 8 
	exampleCircularBuffer.DisplayBuffer();
    
    cout << "Add front\n";
	exampleCircularBuffer.pushFront(5);
	exampleCircularBuffer.pushFront(4);
	exampleCircularBuffer.pushFront(3);
	// 3 4 5 6 7 8 
	exampleCircularBuffer.DisplayBuffer();
	
	cout << "Delete front\n";
	exampleCircularBuffer.popFront();
	// 4 5 6 7 8 
	exampleCircularBuffer.DisplayBuffer();	
	
	cout << "Delete back\n";
	exampleCircularBuffer.popBack();
	// 4 5 6 7 
	exampleCircularBuffer.DisplayBuffer();	
	
	cout << "Full buffer\n";
	for(int i = 8; i < 12; i++) {
	    exampleCircularBuffer.pushBack(i);
	}
	// 4 5 6 7 8 9 10 11 
	exampleCircularBuffer.DisplayBuffer();
	
	cout << "Add back\n";
	exampleCircularBuffer.pushBack(12);
	exampleCircularBuffer.pushBack(13);
	// 6 7 8 9 10 11 12 13 
	exampleCircularBuffer.DisplayBuffer();
	
	cout << "Add front\n";
	exampleCircularBuffer.pushFront(5);
	exampleCircularBuffer.pushFront(4);
	// 4 5 6 7 8 9 10 11
	exampleCircularBuffer.DisplayBuffer();
	
	cout << "\n----------------\nSecond example\n";
	CircularBuffer secondExample;
	secondExample.DisplayBuffer();
	// capacity: 10
    // size: 0
	secondExample.sizeBuffer();
	cout << "pop back\n";
	// Buffer is empty
	secondExample.popBack();
	cout << "pop front\n";
	// Buffer is empty
	secondExample.popFront();
    cout << "\n----------------\n";

	return 0;
}
/*
Output:
Create
6 
Add back
6 7 8 
Add front
3 4 5 6 7 8 
Delete front
4 5 6 7 8 
Delete back
4 5 6 7 
Full buffer
4 5 6 7 8 9 10 11 
Add back
6 7 8 9 10 11 12 13 
Add front
4 5 6 7 8 9 10 11 

----------------
Second example

capacity: 10
size: 0
pop back
Buffer is empty
pop front
Buffer is empty

----------------

Buffer deleted

Buffer deleted
*/