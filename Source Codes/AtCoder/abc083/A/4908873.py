A,B,C,D =map(int,input().split())
X =A+B
Y =C+D
if X > Y:
    print('Left')
elif X < Y:
    print('Right')
elif X==Y:
    print('Balanced')