# ??
N,T=map(int,input().split())

# ????
s=0

# ?????????
a=int(input())

for i in range(N-1):
  # ???????????
  b=int(input())

  # ????????????????????
  if b-a<T:
    s+=b-a
  # ????????????????????
  else:
    s+=T
  # ??????????
  a=b

# ????????????????
s+=T

# ??
print(s)