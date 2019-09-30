import sys

def solve(num):
    if int(num) == 0:
        return ''
    if len(num) == 1:
        return num

    candid = solve(num[1:])
    if candid == '':
        return ('0' if num[0] == '1' else str(int(num[0])-1)) + "9" * (len(num)-1)
    elif num[0] <= candid[0]:
        return num[0] + candid
    else:
        return ('0' if num[0] == '1' else str(int(num[0])-1)) + "9" * (len(num)-1)

test_num = int(input())
for i in range(1, test_num+1):
    ans = solve(input().strip())
    while ans[0] == '0':
        ans = ans[1:]
    print("Case #%d: %s" % (i, ans))

    print(i, file=sys.stderr)
