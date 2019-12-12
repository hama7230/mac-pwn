import lldb
import os



def __lldb_init_module(debugger, dict):
    # print("hoge")
    # file_path = os.path.realpath(__file__)
    # dir_name = os.path.dirname(file_path)
    # print(file_path)
    # print(dir_name)
    debugger.HandleCommand('command script add -f peda_lldb.do_hello hello  -h "Get info about an address in memory"')

def do_hello(debugger, command, result, dict):
    print("hello")


