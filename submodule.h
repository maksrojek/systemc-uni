#pragma once
#include <systemc.h>

SC_MODULE(submodule) {
	sc_in_clk clock;
	sc_in<sc_int<4>> state;

	void task();

	SC_CTOR(submodule) {

		SC_METHOD(task);
		sensitive << clock.pos();
	}

};