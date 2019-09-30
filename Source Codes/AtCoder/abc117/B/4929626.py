#ABC117 B
N = int(input())
Ln = list(map(int, input().split()))
Ln.sort(reverse=True)
max = Ln[0]
sum = sum(Ln)
    
if max < sum - max:
    print("Yes")
else:
    print("No")