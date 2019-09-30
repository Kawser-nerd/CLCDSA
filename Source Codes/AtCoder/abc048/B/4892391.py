a, b, c = map(int, input().split())
print(b//c - (a-1)//c if a !=0 else b//c+1)