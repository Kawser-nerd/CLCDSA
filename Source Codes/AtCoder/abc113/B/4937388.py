N = int(input())
T, A = map(int,input().split())
H = list(map(int,input().split()))
k = []
for i in H:
    k.append(abs(A-(T-i*0.006)))
print(k.index(min(k))+1)