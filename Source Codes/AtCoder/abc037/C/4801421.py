def main() :
    N,K = [int(i) for i in input().split()]
    l = [int(i) for i in input().split()]

    sum_list = getSumList(l)

    res = 0
    for i in range(N-K+1) :
        # res += sum(l[i:i+K])

        if (i == 0) :
            res += (sum_list[i+K-1] - 0)
        else :
            # print(sum_list[i+K-1] - sum_list[i-1])
            res += (sum_list[i+K-1] - sum_list[i-1])


    print(res)


def getSumList(li) :
    sum_list = [0]
    for i in li :
        sum_list.append(sum_list[-1] + i)

    del sum_list[0]
    return sum_list

main()