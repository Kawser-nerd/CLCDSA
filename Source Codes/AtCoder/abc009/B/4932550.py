n = int(input())
a = [int(input()) for i in range(n)]
a = sorted(set(a),reverse=True)
print(a[1])