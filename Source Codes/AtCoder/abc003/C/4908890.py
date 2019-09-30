N,K = map(int,input().split())
R = input().split()

for i in range (N-1):
    for j in range (i+1,N):
        if int(R[i])<int(R[j]):
            tmp = R[i]
            R[i] = R[j]
            R[j] = tmp
R = R[0:K]
R.reverse()

sum = 0
for i in range(K):
    sum += int(R[i])*2**i
sum /= 2**K

print(sum)