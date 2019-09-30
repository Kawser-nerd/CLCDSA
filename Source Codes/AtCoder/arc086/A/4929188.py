import collections
N,K=map(int,input().split(' '))
A=list(map(int,input().split(' ')))
counter=sorted(list(collections.Counter(A).values()))
print(sum(counter[:(len(counter)-K)]))