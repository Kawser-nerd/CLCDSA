k = int(input())
fibs = [1,1]
for i in range(k-1):
 fibs.append(fibs[i] + fibs[i+1])
print(fibs[-2],fibs[-1])