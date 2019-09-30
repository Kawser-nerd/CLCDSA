# ????
from itertools import accumulate


N, Q = map(int, input().split())
lst_operation_imosu = [0] * (N+2)


for _ in range(Q):
    l, r = map(int, input().split())
    lst_operation_imosu[l] += 1
    lst_operation_imosu[r+1] -= 1
lst_operation_num = list(accumulate(lst_operation_imosu))

ans = "".join([str(x%2) for x in lst_operation_num[1:N+1]])
print(ans)