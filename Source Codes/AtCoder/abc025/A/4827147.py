S = input()
N = int(input())
a = S[(N - 1) // 5]
b = S[(N - 1) % 5]
print(a + b)