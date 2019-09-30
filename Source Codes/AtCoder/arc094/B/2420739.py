from math import ceil
q = int(input())
for _ in range(q):    
    a, b = sorted(map(int, input().split()))
    print(min(b-a, max((ceil((a*b)**0.5-a)-1)*2, (ceil((-(2*a-1)+(1+4*a*b)**0.5)/2)-1)*2-1, 0)) + 2*(a-1))