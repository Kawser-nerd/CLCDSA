A,B = map(int,input().split())
if 0 in [A%3, B%3,(A+B)%3]:
    print("Possible")
else:
    print("Impossible")