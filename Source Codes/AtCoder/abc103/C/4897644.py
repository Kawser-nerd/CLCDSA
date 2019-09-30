from functools import reduce
from operator import mul
from sys import stdin
n = int(stdin.readline().rstrip())
al = [int(_) for _ in stdin.readline().rstrip().split()]
m = reduce(mul, al)-1
print(sum(m%a for a in al))