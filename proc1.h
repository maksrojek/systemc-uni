#pragma once
#include <systemc.h>
#include "submodule.h"

SC_MODULE(proc1) {
	sc_in_clk clock;
	sc_fifo_out<int> fifo_out;

	submodule subm;
	sc_signal<sc_int<4>> state;

	void task1();
	void task2();
	void task3();
	void task4();
	void task5();

	SC_CTOR(proc1)
		: subm("subm")
	{
		state.write(0);
		subm.clock(clock);
		subm.state(state);

		SC_THREAD(task1);
		sensitive << clock.pos();

		SC_METHOD(task2);
		sensitive << clock.pos();

		SC_METHOD(task3);
		sensitive << clock.pos();

		SC_METHOD(task4);
		sensitive << clock.pos();

		SC_METHOD(task5);
		sensitive << clock.pos();
	}

};