s=input()
k=int(input())
list=[]
for i in range(len(s)-k+1):
  list.append(s[i:i+k])
print(len(set(list)))