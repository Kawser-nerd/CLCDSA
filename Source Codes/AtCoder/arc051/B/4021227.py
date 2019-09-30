fib=[1,1]
for i in range(50):
    fib.append(fib[len(fib)-1]+fib[len(fib)-2])

K=int(input())

print(fib[K-1],fib[K])