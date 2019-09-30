ans1, ans2 = -1, -1
anss1, anss2 = '', ''

def main():
    T = input()

    for t in range(1, T+1):
        a, b = map(str.strip, raw_input().split())

        a = list(a)
        b = list(b)

        a_org = a[:]
        b_org = b[:]

        global ans1, ans2
        ans1, ans2 = -1, -1


        def solve(i, bigg):
            if i == len(a):
                global ans1, ans2
                global anss1, anss2
                num1 = int(''.join(a))
                num2 = int(''.join(b))
                abs1 = abs(ans1-ans2)
                abs2 = abs(num1-num2)
                if ans1 == -1 or abs1 > abs2 or (
                    abs1 == abs2 and (ans1, ans2) > (num1, num2)):

                    ans1, ans2 = num1, num2;
                    anss1, anss2 = ''.join(a), ''.join(b)
                return

            a[i] = a_org[i]
            b[i] = b_org[i]

            if bigg > 0:
                if a[i] == '?':
                    a[i] = '0'
                if b[i] == '?':
                    b[i] = '9'

                solve(i+1, bigg)

            elif bigg < 0:
                if a[i] == '?':
                    a[i] = '9'
                if b[i] == '?':
                    b[i] = '0'

                solve(i+1, bigg)

            elif bigg == 0:
                # solve => same
                if a[i] == '?' or b[i] == '?' or a[i] == b[i]:
                    if a[i] == '?' and b[i] == '?':
                        a[i] = '0'
                        b[i] = '0'
                    elif a[i] == '?':
                        a[i] = b[i]
                    elif b[i] == '?':
                        b[i] = a[i]

                    solve(i+1, 0)

                # solve => a big
                a[i] = a_org[i]
                b[i] = b_org[i]

                if a[i] == '?' and b[i] == '?':
                    a[i], b[i] = '1', '0'
                elif a[i] == '?' and b[i] != '9':
                    a[i] = chr(ord(b[i])+1)
                elif b[i] == '?' and a[i] != '0':
                    b[i] = chr(ord(a[i])-1)

                if a[i] != '?' and b[i] != '?' and a[i] > b[i]:
                    solve(i+1, 1)

                # solve => b big
                a[i] = a_org[i]
                b[i] = b_org[i]

                if a[i] == '?' and b[i] == '?':
                    a[i], b[i] = '0', '1'
                elif a[i] == '?' and b[i] != '0':
                    a[i] = chr(ord(b[i])-1)
                elif b[i] == '?' and a[i] != '9':
                    b[i] = chr(ord(a[i])+1)

                if a[i] != '?' and b[i] != '?' and a[i] < b[i]:
                    solve(i+1, -1)

        solve(0, 0)

        print "Case #%d: %s %s" % (t, anss1, anss2)

main()
