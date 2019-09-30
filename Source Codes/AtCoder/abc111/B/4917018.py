N = input()
digit_3 = int(N[2])
N = int(N)
nums = [111,222,333,444,555,666,777,888,999]
for num in nums[::-1]:
    temp = num - N
    if temp < 111:
        print(num)
        break