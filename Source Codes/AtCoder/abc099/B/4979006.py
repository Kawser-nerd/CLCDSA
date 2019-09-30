a, b = map(int, input().split())

def calc(n):
    count = 0
    for i in range(1, n+1):
        count += i
    return count

print(calc(b - a) - b)