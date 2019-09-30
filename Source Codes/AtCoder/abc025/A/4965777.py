s=input()
n=int(input())
arr=[]
for i in range(5):
  for j in range(5):
    arr.append(s[i]+s[j])
arr=sorted(arr)
print(arr[n-1])