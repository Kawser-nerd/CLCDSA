n = int(input())
cnt=0
a = []
for i in range(max(1,n-162+1),n+1):
    if eval('+'.join(list(str(i))))==n-i:
        cnt+=1
        a.append(i)
print(cnt)
for i in a:
    print(i)