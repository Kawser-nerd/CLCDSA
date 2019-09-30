import sys
def inpl(): return [int(i) for i in input().split()]

H, W = inpl()
if H%3 == 0 or W%3 == 0:
    print(0)
    sys.exit()
if H == 2 or W == 2:
    print(1)
    sys.exit()

a = W//3
b = W%3
c = H//3
d = H%3

ans = float('inf') 

for i in range(b+1):
    ans = min(ans,max(H*(a+i),(H//2+H%2)*(W-a-i),(H//2)*(W-a-i))-\
              min(H*(a+i),(H//2+H%2)*(W-a-i),(H//2)*(W-a-i)))
for i in range(d+1):
    ans = min(ans,max(W*(c+i),(W//2+W%2)*(H-c-i),(W//2)*(H-c-i))-\
              min(W*(c+i),(W//2+W%2)*(H-c-i),(W//2)*(H-c-i)))
print(min(ans,H,W))