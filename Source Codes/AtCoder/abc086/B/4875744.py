def main():
    print('YNeos'[not(int(''.join(input().split())) ** 0.5).is_integer()::2])


main()