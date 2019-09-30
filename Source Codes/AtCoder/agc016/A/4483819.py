# -*- coding: utf-8 -*-


def main():
    s = input()

    if len(set(s)) == 1:
        print(0)
        exit()

    alphabets = [chr(ord('a') + i) for i in range(26)]
    ans = float('inf')

    for alphabet in alphabets:
        t = s
        count = 0

        while len(t) >= 2:
            t_dash = ''

            for i in range(len(t) - 1):
                if t[i] == alphabet or t[i + 1] == alphabet:
                    t_dash += alphabet
                else:
                    t_dash += t[i]

            count += 1
            t = t_dash

            if len(set(t_dash)) == 1:
                break

        ans = min(ans, count)

    print(ans)


if __name__ == '__main__':
    main()