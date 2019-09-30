A,B = map(int,input().split(" "))
if abs(A) == abs(B):
    print("Draw")
elif abs(A) < abs(B):
    print("Ant")
elif abs(B) < abs(A):
    print("Bug")