#include "proc2.h"

void proc2::task() {
	while (true) {
		int temp = fifo_in.read();
		if (temp == 5) {
			cout << "proc2-task: state: " << temp << endl;
		}
	}
}