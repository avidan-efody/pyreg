module reg_test();

   import "DPI-C" context task init_test(string python_module, string py_reg_test_name);
   import "DPI-C" context task start_test();
   export "DPI-C" task write_reg; 

   task write_reg(int addr, int data);
      #1;
      $display("writing addr %d with data %d at time %d", addr, data, $time);
   endtask
 

   initial begin
       init_test("register_tests", "write_cfg");
       start_test();
   end

endmodule