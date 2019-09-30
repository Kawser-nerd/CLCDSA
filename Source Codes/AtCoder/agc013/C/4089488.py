#import sys
#input = sys.stdin.readline
#template input
import bisect

def IT(): #??1?
    return int(input())
def IL(): #????
    return [int(_) for _ in input().split()]
def IS(): #?????
    return [_ for _ in input().split()]
def ILS(n): #??1???????????????
    return [int(input()) for _ in range(n)]
def SLS(n): #?????????????????
    return [input() for _ in range(n)]
def ILSS(n): #??????????????????
    return [[int(_) for _ in input().split()] for j in range(n)]

#template technique
def bit_full_search(ss):
    n = len(ss)
    for i in range(1 << n):
        s = ""
        for j in range(n + 1):
            if ((1 & i >> j) == 1):
                s += ss[j]
        print(s)

def bit_full_search2(A):
    #https://blog.rossywhite.com/2018/08/06/bit-search/
    value = []
    for i in range(1 << len(A)):
        output = []

        for j in range(len(A)):
            if ((i >> j) & 1) == 1:
                #output.append(A[j])
                output.append(A[j])
        value.append([format(i, 'b').zfill(16), sum(output)])

    value.sort(key=lambda x:x[1])
    bin = [value[k][0] for k in range(len(value))]
    val = [value[k][1] for k in range(len(value))]
    return bin, val

def matching_bisect(list1_val, list2_val, n):
    #2???
    j = 0
    for i in range(len(list1_val)):
        j = bisect.bisect_left(list2_val, n - list1_val[i])
        if j < len(list2_val):
            if list1_val[i] + list2_val[j] == n:
                #ans = list2_bin[j] + list1_bin[i]
                break
    return j

"""??????????"""
def main():
    n, l, t = IL()
    xw = ILSS(n)

    first_ant_number = 1
    first_ant_direction = xw[0][1]
    first_ant_position0 = xw[0][1]
    if first_ant_direction == 1:
        first_ant_position = (xw[0][0] + t) % l
    else:
        first_ant_position = (xw[0][0] - t) % l

    for i in range(n):
        if xw[i][1] == 1:
            first_ant_number = i + 1
            first_ant_position0 = xw[i][0]
            first_ant_position = (xw[i][0] + t) % l
            first_ant_direction = xw[i][1]
            break

    for i in range(n):
        if first_ant_direction != xw[i][1]:

            if t <= ((xw[i][0] - first_ant_position0) % l )/ 2:
                hit_count = 0
            else:
                dt =((xw[i][0] - first_ant_position0) % l )
                hit_count = 1 + int((2 * t - dt - 0.001) // l)
            first_ant_number = (first_ant_number + hit_count) % n
            if first_ant_number == 0:
                first_ant_number = n

    ant_position = []
    for i in range(n):
        if xw[i][1] == 1:
            pos = (xw[i][0] + t) % l
        else:
            pos = (xw[i][0] - t) % l
        ant_position.append(pos)
    ant_position.sort()

    ans = [0 for i in range(n)]
    for i in range(n):
        if first_ant_position == ant_position[i]:
            start = i
            break
    for i in range(n):
        ans[(first_ant_number - 1 + i) % n] = ant_position[(start + i) % n]

    for i in range(n):
        print(ans[i])

main()