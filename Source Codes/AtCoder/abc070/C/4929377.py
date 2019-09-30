import fractions


def lcm(a, b):
    return a * b // fractions.gcd(a, b)


def list_lcm(number_list):
    lcm_number = 1
    for j in range(len(number_list)):
        lcm_number = lcm(lcm_number, number_list[j])

    return lcm_number


if __name__ == '__main__':
    number_count = int(input())
    numbers = []
    for i in range(number_count):
        numbers.append(int(input()))
    print(int(list_lcm(numbers)))