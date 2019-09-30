S=input()
A,B,C,D=map(int,input().split())
a=S[:A]+'"'+S[A:B]+'"'+S[B:C]+'"'+S[C:D]+'"'+S[D:]
print(a)