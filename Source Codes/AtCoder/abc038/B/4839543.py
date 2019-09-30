H, W = map(int, input().split())

h, w = map(int, input().split())

print("YES" if H == h or H == w or W == h or W == w else "NO")