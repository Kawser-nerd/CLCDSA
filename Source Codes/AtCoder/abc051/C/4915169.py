sx, sy, tx, ty = map(int, input().split())
x = tx - sx
y = ty - sy
r1 = "R"*x + "U"*y
r2 = "L"*x + "D"*y
r3 = "D" + "R"*(x+1) + "U"*(y+1) + "L"
r4 = "U" + "L"*(x+1) + "D"*(y+1) + "R"
ans = r1 + r2 + r3 + r4
print(ans)