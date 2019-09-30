#12
a = int(input())
b = int(input())
print(min(abs(a-b), min(a,b)+(10-max(a,b))))