from copy import deepcopy as dc
import sys

def swap(a,b,l):
  s=dc(l)
  s[a],s[b]=s[b],s[a]
  return s

def diff(e,d):
  cnt=0
  for i in range(len(e)):
    if e[i]!=d[i]:
      cnt+=1
  return cnt

input=sys.stdin.readline
n,k=map(int,input().split())
S=input()[:-1]
m=list(S)
c=[i for i in m]
for i in range(n):
  x=i
  for j in range(i+1,n):
    if (c[x]>c[j]) and (diff(m,swap(i,j,c))<=k):
      x=j
  c=swap(i,x,c)
print("".join(c))