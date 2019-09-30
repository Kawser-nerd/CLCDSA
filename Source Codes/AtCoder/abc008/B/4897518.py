import collections
n=int(input())
d=[]
for i in range(n):
    a=str(input())
    d.append(a)
d1=collections.Counter(d)
print(d1.most_common()[0][0])