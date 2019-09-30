sx, sy, tx, ty = map(int, input().split())
dy = ty - sy
dx = tx - sx
print("U"*(dy)+"R"*(dx)+"D"*(dy)+"L"*(dx)+"L"+"U"*(dy+1)+"R"*(dx+1)+"D"+"R"+"D"*(dy+1)+"L"*(dx+1)+"U")