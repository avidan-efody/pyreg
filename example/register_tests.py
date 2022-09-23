import py2sv

class write_cfg:
    def __init__(self):
        self.reg = "cfg"

    def start_test(self):
        print("register write start")
        py2sv.write_reg(3, 2)
        print("register write done")

        return self.reg

def get_test(test_name):
    if (test_name == "write_cfg"):
        return write_cfg()

