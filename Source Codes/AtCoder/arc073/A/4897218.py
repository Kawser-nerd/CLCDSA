N,T=map(int,input().split(' '))
times=list(map(int,input().split(' ')))
print(sum([min(T, times[i+1]-times[i]) for i in range(N-1)])+T)