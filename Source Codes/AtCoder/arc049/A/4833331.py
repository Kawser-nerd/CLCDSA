a=list(input())
for i in input().split()[::-1]:a.insert(int(i),"\"")
print("".join(a))