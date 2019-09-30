W, A, B = map(int, input().split())
print(max(0, A - B - W, B - A - W))