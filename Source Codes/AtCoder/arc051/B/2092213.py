k = int(input())
fib = [1]*50
for i in range(2,50):
    fib[i] = fib[i-1] + fib[i-2]
print(fib[k+1],fib[k])