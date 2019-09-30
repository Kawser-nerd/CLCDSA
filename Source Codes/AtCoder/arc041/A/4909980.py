omote, ura = map(int, input().split())
k = int(input())

if ura >= k:
    print(omote + k)
else:
    print(omote + ura - (k-ura))