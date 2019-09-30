K = int(input())

odd = []
even = []
for i in range (K):
    if i%2 ==0:
        even.append(i)
    else:
        odd.append(i)
print(len(even)*len(odd))