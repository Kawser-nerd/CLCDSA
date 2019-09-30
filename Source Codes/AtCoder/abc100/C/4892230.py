N = int(input())
a = map(int,input().split())

def counter(x):
    num = 0
    while x%2==0:
        num += 1
        x /= 2
    return num

s = [counter(i) for i in a]
print(sum(s))