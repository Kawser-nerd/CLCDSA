import collections
n=int(input())
a=[int(input()) for i in range(n)]
ad=collections.Counter(a)
counter=0
for i in ad.values():
    if i%2==1:
        counter+=1
print(counter)