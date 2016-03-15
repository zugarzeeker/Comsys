#include "reg4bit.h"
// #include "reg4_.h"
 
SC_MODULE(reg16) {
 
    sc_in<bool >  clk;
    sc_in<bool >  reset;
    sc_in<bool > enable, rw, clr; 
    sc_out<sc_uint<16> > dout;
    sc_in<sc_uint<16> >  din;

    sc_signal<sc_uint<4> > _d[4], _q[4];
    sc_uint<16> d,q;

    sc_out<bool> ready;

    reg4 reg4_1, reg4_2, reg4_3, reg4_4;

    sc_signal<bool> ready_reg4_1, ready_reg4_2, ready_reg4_3, ready_reg4_4;

    sc_uint<4> ready_reg4;

    void p1()
    {
        // while (true) {
        //   wait();
          d = din.read();
          for (int i = 0; i < 4; i++) {
            _d[i] =  d(i*4+3, i*4);
          }
      // }
    }
  
    void p2()
    { 
        // while (true) {
        //   wait();
          for (int i = 0; i < 4; i++) {
            q(i*4+3, i*4) = _q[i];
          }
          dout.write(q);
        // }
    }

    // void run() {
    //     while (true) {
    //         wait();
    //         ready.write(false);
    //         p1();
    //         p2();
    //         // while (ready.read() != true) {
    //             ready_reg4[0] = ready_reg4_1.read();
    //             ready_reg4[1] = ready_reg4_2.read();
    //             ready_reg4[2] = ready_reg4_3.read();
    //             ready_reg4[3] = ready_reg4_4.read();

    //             ready.write(ready_reg4.and_reduce());
    //             // wait();
    //         // }
    //     }
    // }
 
    SC_CTOR(reg16) : reg4_1("reg4_1"), reg4_2("reg4_2"), reg4_3("reg4_3"), reg4_4("reg4_4") {
    

    SC_METHOD(p1);
    sensitive << clk.pos();
    SC_METHOD(p2);
    sensitive << clk.pos();
    

    // SC_CTHREAD(p1, clk);
    // SC_CTHREAD(p2, clk);

    // SC_CTHREAD(run, clk);

    
    d=0; q=0;

    reg4_1.clk(clk);
    reg4_1.reset(reset);
    reg4_1.din(_d[0]);
    reg4_1.dout(_q[0]);
 
    reg4_2.clk(clk);
    reg4_2.reset(reset);
    reg4_2.din(_d[1]);
    reg4_2.dout(_q[1]);

    reg4_3.clk(clk);
    reg4_3.reset(reset);
    reg4_3.din(_d[2]);
    reg4_3.dout(_q[2]);

    reg4_4.clk(clk);
    reg4_4.reset(reset);
    reg4_4.din(_d[3]);
    reg4_4.dout(_q[3]);
  
    reg4_1.enable(enable);
    reg4_1.rw(rw);
    reg4_1.clr(clr);

    reg4_2.enable(enable);
    reg4_2.rw(rw);
    reg4_2.clr(clr);

    reg4_3.enable(enable);
    reg4_3.rw(rw);
    reg4_3.clr(clr);

    reg4_4.enable(enable);
    reg4_4.rw(rw);
    reg4_4.clr(clr);

    reg4_1.ready(ready_reg4_1);
    reg4_2.ready(ready_reg4_2);
    reg4_3.ready(ready_reg4_3);
    reg4_4.ready(ready_reg4_4);
  }
};
