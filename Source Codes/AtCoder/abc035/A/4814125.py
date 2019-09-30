W, H = map(int, input().split())

if float(W / H) == float(4 / 3):
    print("4:3")
elif float(W / H) == float(16 / 9):
    print("16:9")