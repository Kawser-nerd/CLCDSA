n = int(input())
for t in range(10**9):
    n-= t
    if n<=0: print(t); break