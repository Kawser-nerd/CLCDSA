A, B, K = map(int, input().split())

l = [i for i in range(A, A + K) if i <= B]
li = l + [i for i in range(B - K + 1, B + 1) if i >= A]

for i in sorted(set(li)):
    print(i)