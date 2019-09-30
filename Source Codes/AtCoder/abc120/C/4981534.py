if __name__ == '__main__':
    string = input()
    zero_count = string.count('0')
    one_count = string.count('1')
    print(min(zero_count, one_count) * 2)