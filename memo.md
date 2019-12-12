## lldb
* disassemble -n main (= disas main)
* disassemble -a 0x100000f00 (= disas 0x100000f00)
* register read (= i r)
* memory write -s 8 0x00007ffeefbff7f8  0x100000f30 (= set {long}0x00007ffeefbff7f8=0x100000f30)

* settings set target.x86-disassembly-flavor intel disassembleの時の表示をintel記法にする


* otool -L ./bin (= ldd)

* https://lldb.llvm.org/use/map.html


## libmalloc

* tiny (<1008 0x3f0 ), small (<128k), large

### tiny
* no metadata in used chunk
* metadata in freed chunk
    * prev, 
    * next

