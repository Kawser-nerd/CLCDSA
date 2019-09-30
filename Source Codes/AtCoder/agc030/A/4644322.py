A,B,C = map(int,input().split())
can = min(A+B,C)
eat = 0
C -= can
eat += can*2-A
B = A+B -can

if C > 0:
    eat += 1

print(eat+B)