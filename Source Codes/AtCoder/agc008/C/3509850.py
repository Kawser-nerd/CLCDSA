aI, aO, aT, aJ, aL, aS, aZ = map(int, input().split())

x, y, z = sorted([aI, aJ, aL])

ans = aO
if x == 0:
    ans += y//2 * 2 + z//2 * 2
else:
    ans += (x-1) * 3
    y -= x-1
    z -= x-1
    ans += max(3 + (z-1)//2 * 2 + (y-1)//2 * 2, z//2 * 2 + y//2 * 2)

print(ans)