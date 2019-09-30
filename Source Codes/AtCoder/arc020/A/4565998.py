a,b=map(int,input().split())
a=abs(a)
b=abs(b)
print("Draw"if a==b else("Ant" if a<b else"Bug"))