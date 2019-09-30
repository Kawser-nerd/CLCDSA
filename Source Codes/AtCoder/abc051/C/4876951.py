sx, sy, tx, ty = map(int, input().split())
ans = ""
#???
ans += "R"*(tx-sx)
ans += "U"*(ty-sy)
ans += "L"*(tx-sx)
ans += "D"*(ty-sy)
#???
ans += "D"
ans += "R"*(tx-sx+1)
ans += "U"*(ty-sy+1)
ans += "L"
ans += "U"
ans += "L"*(tx-sx+1)
ans += "D"*(ty-sy+1)
ans+="R"
print(ans)