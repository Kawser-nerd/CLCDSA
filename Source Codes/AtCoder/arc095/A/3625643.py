N = int(input())

a = list(map(int,input().split(' ')))

sorted_a = sorted(a)

for i in range(N):
    if a[i] < sorted_a[int(N/2)]:
        print(sorted_a[int(N/2)])
    else:
        print(sorted_a[int(N/2)-1])