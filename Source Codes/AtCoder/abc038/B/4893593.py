h1,w1=map(int,input().split())
h2,w2=map(int,input().split())
print("YES" if h1 in [h2,w2] else "YES" if w1 in [h2,w2] else "NO")