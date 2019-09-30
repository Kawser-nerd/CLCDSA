n = int(input())
ten = n // 10
one = n % 10
print(min((ten + 1) * 100, ten * 100 + one * 15))