sx,sy,tx,ty = map(int,input().split())
dx = tx - sx
dy = ty - sy
ans = "U"*dy+"R"*dx
ans +="D"*dy+"L"*dx
ans += "L"+"U"*(1+dy)+"R"*(1+dx)+"D"
ans += "R"+"D"*(1+dy)+"L"*(1+dx)+"U"
print(ans)