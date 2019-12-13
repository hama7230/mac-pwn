# 
## tiny unlink attack
checksumのブルーとフォースに成功すると、以下のようになる。unlink attackにより0xdeadbeefが0xbadになった。
```
% ./a.out                                                                                                                                (git)-[master]
p = 0x7fbe25401910, q = 0x7fbe25401b10, r = 0x7fbe25401d10
q[0] = 5000000000000000, q[1] = 5000000000000000
target = deadbeef, &target = 0x108ae3030
target = bad, &target = 0x108ae3030
```
