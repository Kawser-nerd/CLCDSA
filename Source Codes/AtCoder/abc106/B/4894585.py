n = int(input())
def get_factors(n):
    f = set()
    for i in range(1,int((n**0.5))+1):
        if n % i == 0:
            f.add(i)
            f.add(n//i)
    return len(f)
ans = 0
for i in range(1,n+1):
    if get_factors(i) == 8 and i % 2 == 1:
        ans += 1
print(ans)