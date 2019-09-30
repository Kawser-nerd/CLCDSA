N, A, B = map(int, input().split())

if N <= 5:
    res = B * N
    
else:
    res = B * 5
    res += (N - 5) * A
    
print(res)