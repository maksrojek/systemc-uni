#include <systemc.h>
#include "proc1.h"
#include "proc2.h"

int sc_main(int argc, char* argv[]) {
	sc_clock clock("my_clock", 1, 0.5);
	sc_fifo<int> fifo(5);

	proc1 p1("p1");
	p1.clock(clock);
	p1.fifo_out(fifo);

	proc2 p2("p2");
	p2.clock(clock);
	p2.fifo_in(fifo);

	sc_start();

	system("pause");
	return 0;
}