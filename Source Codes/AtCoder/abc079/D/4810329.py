def main():
    H, W = map(int, input().split())
    g_list = []
    for i in range(10):
        g_list.append(list(map(int, input().split())))
    min_change = [j[1] for j in g_list]
    flag = [0 for _ in range(10)]
    tep = [(j,g) for j, g in enumerate(min_change) if j != 1]  
    min_g = min(tep, key=lambda a:a[1])[0]
    flag[min_g] = 1
    #print(min_change, flag, min_g)
    while sum(flag) != 9:
        #print(min_change, flag)
        for j in range(10):
            if g_list[j][min_g] + min_change[min_g] < min_change[j]:
                min_change[j] = g_list[j][min_g] + min_change[min_g]
        tep = [(k,g) for k, g in enumerate(min_change) if flag[k] == 0 and k != 1]
        if tep != []:
            min_g = min(tep, key=lambda a:a[1])[0]
        else :
            break
        flag[min_g] = 1
    s = 0
    for i in range(H):
        wall = list(map(int, input().split()))
        s += sum([min_change[i] for i in wall if i != -1])
    return s
        
if __name__ == '__main__':
    print(main())