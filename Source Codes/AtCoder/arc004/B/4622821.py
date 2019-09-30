N=int(input())
K=[]
for i in range(N):
    l=int(input())
    K.append(l)
print(sum(K))
print(max(0,max(K)*2-sum(K)))