N=int(input())
an=input()
ans=str(an)
mi=N
ma=0
for i in range(1,5):
  A=ans.count(str(i),0)
  if A<mi:
    mi=A
for i in range(1,5):
  A=ans.count(str(i),0)
  if A>ma:
    ma=A
print(ma, mi)