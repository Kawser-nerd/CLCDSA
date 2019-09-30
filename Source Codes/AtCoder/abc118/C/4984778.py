def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return a * b // gcd(a, b)


def list_lcm(number_list):
    lcm_number = 1
    for j in number_list:
        lcm_number = lcm(lcm_number, j)

    return lcm_number


def list_gcd(number_list):
    gcd_number = number_list[0]
    for i in number_list:
        gcd_number = gcd(gcd_number, i)

    return gcd_number


if __name__ == '__main__':
    n = input()
    number_list = list(map(int, input().split()))
    print(list_gcd(number_list))