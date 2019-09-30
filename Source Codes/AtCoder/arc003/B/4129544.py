def main() :
    N = int(input())
    str_list = []
    reversed_list = []
    for n in range(N) :
        reversed_list.append(input()[::-1])

    reversed_list.sort()

    for s in reversed_list :
        print(s[::-1])


main()