## lldb
* disassemble -n main (= disas main)
* disassemble -a 0x100000f00 (= disas 0x100000f00)
* register read (= i r)
* memory write -s 8 0x00007ffeefbff7f8  0x100000f30 (= set {long}0x00007ffeefbff7f8=0x100000f30)

* settings set target.x86-disassembly-flavor intel disassembleの時の表示をintel記法にする


* otool -L ./bin (= ldd)

* https://lldb.llvm.org/use/map.html



## libmalloc
* サイズによって使われるアルゴリズム(?)が違う。
    * tiny (<1008 0x3f0 ), small (<128k), large、これはチャンクのサイズかmallocの引数そのものか？
* libsystem\_malloc.dylibで処理される
    * 場所　/usr/lib/system/libsystem_malloc.dylib
* ソースコード は、https://opensource.apple.com/tarballs/libmalloc/


### tiny
* 使用中のチャンクにはメタデータはない。glibcにおけるsizeなどはなくて、データは連続している。つまりnullがないとリークの可能性。
* freeしたチャンクはメタデータが存在する
    * prev: 前のfreeされたチャンクを指す
    * next: 次のfreeされたチャンクを指す
    * ポインタは右シフトされており、チェックサムと一緒にまとめられる
    * チェックサムは4bit, Checksum = SumofEverybytes(ptr^cookie) & 0xf
    * heap bofでシフトされたポインタを上書きできたとしても、チェックサムが異なると死ぬ。逆にたかだか4bit(32回程度)のブルーとフォースで当てられるので、何とでもなる
    * msize: glibcでのprev size的なやつ。変なところにいる。　
* tiny\_header\_inuse\_pair\_t
    * tinyのチャンクを管理する変数(構造?)
    * けつにいる。
    * bitmapでどの領域が使用中かどうか管理
    * header, inuseの2つで管理し、どこにメタデータのヘッダがあるか判断している。
* magaine 
    * tcacheのようなもの
    * <= 0x100のチャンクはfreeされずに、maginzeに突っ込まれる。次にfreeが呼ばれたときに、処理される。
    
