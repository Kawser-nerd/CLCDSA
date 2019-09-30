sx, sy, tx, ty = map(int, input().split())
dx, dy = (tx-sx), (ty-sy)
print("U"*dy+"R"*dx+"D"*dy+"L"*dx+"L"+"U"*(dy+1)+"R"*(dx+1)+"DR"+"D"*(dy+1)+"L"*(dx+1)+"U")