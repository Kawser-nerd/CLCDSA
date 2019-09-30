N = int(input())
s = input()

Rc = s.count('R')%2
Gc = s.count('G')%2
Bc = s.count('B')%2

print(Rc+Gc+Bc)