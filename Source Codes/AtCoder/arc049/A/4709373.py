slist = list(input())
a = list(map(int,input().split()))
for i,c in enumerate(a):
    slist.insert(c+i,'\"')
print(''.join(slist))