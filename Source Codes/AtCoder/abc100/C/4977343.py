N = int(input())
a = list(map(int, input().split()))

def ctd(n):
    count = 0
    while n % 2 == 0:
        count += 1
        n /= 2
    return count

ctd_l = list(map(ctd, a))
print(sum(ctd_l))