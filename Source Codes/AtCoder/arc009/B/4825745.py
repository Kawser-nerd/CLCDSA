def main():
    b = input().replace(' ', '')
    trans = str.maketrans(b, '0123456789')
    rtrans = str.maketrans('0123456789', b)

    n = int(input())
    a = []
    for _ in range(n):
        a.append(int(input().translate(trans)))
    a.sort()

    for x in a:
        print(str(x).translate(rtrans))

main()