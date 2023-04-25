from z3 import *

s = Solver()

a = BitVec('a', 64)
b = BitVec('b', 64)
g = BitVec('g', 64)
d = BitVec('d', 64)

s.add(b + a == 0xA255CEA0BA)
s.add(g + b == 0xC4259FEEE3)
s.add(g + d == 0x2284419047)
s.add(a + d == 3027255838)
s.add(d^g^b == 0x8391639987)

print(s.check())

print(hex(int(str(s.model()[a]))))
print(hex(int(str(s.model()[b]))))
print(hex(int(str(s.model()[g]))))
print(hex(int(str(s.model()[d]))))