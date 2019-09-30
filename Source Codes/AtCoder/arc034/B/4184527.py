def b_equation(N):
    # x=10**18-1 ????f(x)=9*17=153 ????f(x)??????????
    # ???????x????N-153??N?????????
    is_satisfy_equation = []
    for x in range(N - 153, N + 1):
        if x < 0:
            continue
        f = sum(map(int, list(str(x))))
        if x + f == N:
            is_satisfy_equation.append(x)
    ans = '\n'.join(map(str, [len(is_satisfy_equation)] + is_satisfy_equation))
    return ans

N = int(input())
print(b_equation(N))