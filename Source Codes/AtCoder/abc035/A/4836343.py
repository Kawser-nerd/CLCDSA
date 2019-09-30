w, h = map(int, input().split())
if round(w/h, 2) == 1.33:
    print("4:3")
else:
    print("16:9")