N = int(input())

for item in sorted([input()[::-1] for _ in range(N)]):
    print(item[::-1])