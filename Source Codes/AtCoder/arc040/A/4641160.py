n = int(input())
maps = ""
for _ in range(n):
    maps += str(input())
R = maps.count("R")
B = maps.count("B")
if R > B :
    print('TAKAHASHI')
elif R == B:
    print("DRAW")
else:
    print("AOKI")