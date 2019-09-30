K=int(input())
even=[]
odd=[]
for i in range(1,K+1):
    if i%2==0:
        even.append(i)
    else:
        odd.append(i)
print(len(even)*len(odd))