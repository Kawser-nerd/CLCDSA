a, b = map(int, input().split())
diff = b - a
#ans = (1+2+....+diff) - b

print(sum(list(range(1, diff + 1))) - b)