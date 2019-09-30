a = int(input())
b = int(input())
ans = min(((b-a)%10), (a-b)%10)
print(ans)