I = list(map(int,input().split()))
I.sort()
print(I[4]+I[3]+I[0] if I[4]+I[3]+I[0] > I[4]+I[2]+I[1] else I[4]+I[2]+I[1])