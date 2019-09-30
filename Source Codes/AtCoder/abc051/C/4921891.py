sx,sy,tx,ty = map(int,input().split())
x=tx-sx
y=ty-sy
S="L"
S+="U"*(y+1)
S+="R"*(x+1)
S+="D"*(y+1)
S+="L"*(x)
S+="U"*(y)
S+="R"*(x+1)
S+="D"*(y+1)
S+="L"*(x+1)
S+="U"
print(S)