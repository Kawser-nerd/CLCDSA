numbers=[int(input()) for i in range(3)]
s_numbers=sorted(numbers, reverse=True)
for i in numbers:
    print((s_numbers.index(i))+1)