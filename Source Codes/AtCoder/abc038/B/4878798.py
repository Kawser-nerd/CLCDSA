a,b=map(int,input().split())
c,d=map(int,input().split())
print("YES"if{a,b}&{c,d}!=set()else"NO")