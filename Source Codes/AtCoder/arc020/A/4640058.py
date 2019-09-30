a,b = map(int,input().split())
a,b = abs(a),abs(b)
if a < b:
    print("Ant")
elif a == b:
    print("Draw")
else:
    print("Bug")