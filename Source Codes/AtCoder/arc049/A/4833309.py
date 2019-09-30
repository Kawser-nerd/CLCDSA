a=list(input())
for i in map(int,input().split()[::-1]):a.insert(i,"\"")
print("".join(a))