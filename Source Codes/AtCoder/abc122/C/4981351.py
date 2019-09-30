if __name__ == '__main__':
    length, question_count = map(int, input().split())

    string = input()
    ac_sums = [0]
    for i in range(1, len(string) + 1):
        if i > 1 and string[i - 2] == 'A' and string[i - 1] == 'C':
            ac_sums.append(ac_sums[i - 1] + 1)
        else:
            ac_sums.append(ac_sums[i - 1])

    for i in range(question_count):
        l, r = map(int, input().split())
        ans = ac_sums[r] - ac_sums[l - 1]
        if l > 1 and string[l - 1] == 'C' and string[l - 2] == 'A':
            ans -= 1
        print(ans)