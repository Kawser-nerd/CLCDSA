n=int(input())
a,b=map(int,input().split())
k=int(input())
p=[a]+list(map(int,input().split()))+[b]
pp=set(p)
print("YNEOS"[len(pp)!=len(p)::2])