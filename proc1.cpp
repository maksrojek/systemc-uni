#include "proc1.h"

void proc1::task1() {
	int input;
	int sw[5] = {}; // switch state
	int sum;

	while (true) {
		wait();
		// check input
		cin >> input;
		if (input < 0 || input > 5) {
			// stop simulation
			sc_stop();
		}
		if (input != 0) {
			// update switch state
			input += -1;
			if (sw[input] == 0) {
				sw[input] = 1;
			}
			else {
				sw[input] = 0;
			}
			// update state
			sum = 0;
			for (int i = 0; i < 5; i++) {
				sum += sw[i];
			}
			if (sum == 0) {
				state.write(0); // state 0
			}
			else if (sum != 1) {
				state.write(6); // error
			}
			else {
				for (int i = 0; i < 5; i++) {
					if (sw[i] == 1) {
						state.write(i + 1); // state 1-5
						break;
					}
				}
			}
		} // end if (input != 0)

		fifo_out.write(state.read());

		// for debug 
		system("cls");

		for (int i = 0; i < 5; i++) {
			cout << sw[i];
		}
		cout << endl;

	} // end while
}

void proc1::task2() {
	int temp = state.read();
	if (temp == 0) {
		cout << "proc1-task2: state: " << temp << endl;
	}
}

void proc1::task3() {
	int temp = state.read();
	if (temp == 1) {
		cout << "proc1-task3: state: " << temp << endl;
	}
}

void proc1::task4() {
	int temp = state.read();
	if (temp == 2) {
		cout << "proc1-task4: state: " << temp << endl;
	}
}

void proc1::task5() {
	int temp = state.read();
	if (temp == 3) {
		cout << "proc1-task5: state: " << temp << endl;
	}
}
