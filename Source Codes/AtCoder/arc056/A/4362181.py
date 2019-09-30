a, b, k, l = map(int, input().split())
print(min(b*(k//l)+a*(k%l), b*(k//l+1)))