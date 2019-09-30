a,b,c = map(int,input().split())

list = sorted([abs(a-b), abs(b-c), abs(c-a)],reverse=True)

print(list[1]+list[2])