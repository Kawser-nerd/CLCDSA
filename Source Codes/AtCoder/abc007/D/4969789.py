a, b = map(int, input().split())
l=[0, 1, 2, 3, 4, 4, 5, 6, 7, 8]
def count(n):
  N=list(map(int, list(str(n))))
  cnt=0
  for i in range(1, len(N)+1):
    cnt+=l[N[i-1]]*8**(len(N)-i)
    if N[i-1]==4 or N[i-1]==9:
      break
    if i==len(N):
      cnt+=1
  return cnt-1
cnt1=count(b)
cnt2=count(a-1)
print(b-a+1-(cnt1-cnt2))