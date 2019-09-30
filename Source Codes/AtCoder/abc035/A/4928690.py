W, H = map(int, input().split())
print(["4:3", "16:9"][not(W==H//3*4)])