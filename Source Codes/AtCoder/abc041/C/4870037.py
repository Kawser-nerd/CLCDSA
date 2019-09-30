N = int(input())
lst_a = list(map(int, input().split()))

lst_students = []
for i, h in enumerate(lst_a):
    i += 1
    t_student = (i, h)
    lst_students.append(t_student)

lst_height = sorted(lst_students, reverse=True, key=lambda x: x[1])
for h in lst_height:
    ans = h[0]
    print(ans)