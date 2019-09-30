x, a, b = map(int, input().split())
if 0 < b-a <= x: print("safe")
else: print("ddealnigceiroouuss"[b-a>x::2])