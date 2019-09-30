import sys

def remove_bit(num, i):
    high = (num >> (i + 1)) << i
    low = num & ((1 << i) - 1)
    return high + low

def insert_bit(num1, num2, i):
    high = num1 >> i << (i + 1)
    low = num1 & (-1 + (1 << i))
    insert = num2 & (1 << i)
    return high + insert + low

def solve(N, A, B):
    if N == 1:
        return [A, B]

    r_bit = -1
    for i in range(N):
        if (A >> i) & 1 != (B >> i) & 1:
            r_bit = i
            break
    if r_bit == -1:
        import pdb; pdb.set_trace()

    AA = remove_bit(A, r_bit)
    BB = remove_bit(B, r_bit)

    C = -1
    for C in range(2**(N-1)):
        if bin(AA ^ C).count('1') % 2 == 1 and  bin(AA ^ C).count('1') % 2 == 1:
            break
    A_list = solve(N - 1, AA, C)
    B_list = solve(N - 1, C, BB)

    A_list = list(map(lambda x: insert_bit(x, A, r_bit), A_list))
    B_list = list(map(lambda x: insert_bit(x, B, r_bit), B_list))

    return A_list + B_list


def main(N, A, B):
    if (bin(A).count('1') + bin(B).count('1')) % 2 == 0:
        print('NO')
        sys.exit()

    print('YES')
    ans_list = solve(N, A, B)

    assert A == ans_list[0]
    assert B == ans_list[-1]
    for i in range(len(ans_list) - 1):
        assert bin(ans_list[i] ^ ans_list[i+1]).count('1') == 1

    for num in ans_list:
        sys.stdout.write('%d '%num)
    print()



if __name__ == '__main__':
    N, A, B = map(int, input().split())
    main(N, A, B)