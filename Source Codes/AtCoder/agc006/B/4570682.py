N,x = map(int, input().split())
s = 2*N-1
if x == 1 or x == 2*N-1:
    print("No")
else:
    print("Yes")
    for i in range(s):
        print(1 + (x - N + i) % s)