a, b, k, l = map(int, input().split())
print(min(((k-1)//l+1)*b, k//l*b+(k-k//l*l)*a))