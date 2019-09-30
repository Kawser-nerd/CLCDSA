n=2025-int(input())
for i in range(1,10):
    if n%i<1 and n/i<10:print(i,'x',n//i)