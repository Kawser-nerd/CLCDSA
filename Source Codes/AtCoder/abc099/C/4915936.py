if __name__ == '__main__':
    target = int(input())
    withdraw_counts = [0] * (target + 1)

    for i in range(target + 1):
        if i < 6:
            withdraw_counts[i] = i
        elif i < 9:
            withdraw_counts[i] = i - 5
        else:
            needed_withdraw_counts = [withdraw_counts[i-1]]
            exp_n = 1
            while 6 ** exp_n <= i:
                needed_withdraw_counts.append(withdraw_counts[i - 6 ** exp_n])
                exp_n += 1
            exp_n = 1
            while 9 ** exp_n <= i:
                needed_withdraw_counts.append(withdraw_counts[i - 9 ** exp_n])
                exp_n += 1
            withdraw_counts[i] = min(needed_withdraw_counts) + 1
    print(withdraw_counts[target])