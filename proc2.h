#pragma once
#include <systemc.h>

SC_MODULE(proc2) {
	sc_in_clk clock;
	sc_fifo_in<int> fifo_in;

	void task();

	SC_CTOR(proc2) {

		SC_THREAD(task);
		sensitive << clock.pos();
	}

};