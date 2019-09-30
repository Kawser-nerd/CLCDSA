# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
_A, _B = map(int, input().split())
A = _A
B = _B

if A >= 900:
    if A >= 990:
        A = A-(A % 10)+9
    else:
        A = A-((A//10) % 10)*10+90
else:
    A = A - (A//100)*100+900
if B <= 199:
    if B <= 109:
        B = B-(B % 10)
    else:
        B = B-((B//10) % 10)*10
else:
    B = B-(B//100)*100+100
print(max(_A-B, A-_B))