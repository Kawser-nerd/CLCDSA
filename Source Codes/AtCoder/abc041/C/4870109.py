from operator import itemgetter


N = int(input())
lst_a = list(map(int, input().split()))
lst_students = [[i, lst_a[i]] for i in range(N)]

lst_height_sorted = sorted(lst_students, key=itemgetter(1), reverse=True)
for h in lst_height_sorted:
    print(h[0] + 1)