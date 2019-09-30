N = int(input())
minimum = 10**5
for i in range(1,-(-N//2)+1):
    A = i
    B = N - i
    total = 0
    for _ in range(6):
        total += A % 10 + B % 10
        A //= 10
        B //= 10
    if total < minimum:
        minimum = total
print(minimum)