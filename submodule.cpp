#include "submodule.h"

void submodule::task() {
	int temp = state.read();
	if (temp == 4) {
		cout << "submodule: state: " << temp << endl;
	}
	else if (temp == 6) {
		cout << "submodule: state: " << temp << " - error" << endl;
	}
}