N = int(input())
r = input()

ans = r.count('A') * 4 + r.count('B') * 3 + r.count('C') * 2 + r.count('D')

print(ans / N)