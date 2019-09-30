n = int(input())
a = [int(input()) for i in range(n)]
a = sorted(set(a),reverse = True)
if len(a) > 1:
    print(a[1])
else:
    print(a[0])