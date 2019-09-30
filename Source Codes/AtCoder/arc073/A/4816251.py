N,T = map(int,input().split())
t = [int(i) for i in input().split()] + [10**10]

print(sum([min(T,b-a) for a,b in zip(t[:-1],t[1:])]))