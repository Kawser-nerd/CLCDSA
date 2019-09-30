n=int(input())
a=[int(s) for s in input().split()]
print(min(sum((x-p)*(x-p) for x in a) for p in range(min(a),max(a)+1)))