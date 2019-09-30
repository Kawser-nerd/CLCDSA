K = int(input())
def fib(a, b, cnt):
    if K == cnt:
        print(a, b)
        exit()
    else:
        cnt += 1
        fib(a+b, a, cnt)
fib(1, 1, 0)