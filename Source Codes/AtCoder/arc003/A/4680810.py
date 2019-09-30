n=int(input())
r=input()
ct=0
for i in range(n):
  if r[i]=='A':ct+=4
  if r[i]=='B':ct+=3
  if r[i]=='C':ct+=2
  if r[i]=='D':ct+=1
print(ct/n)