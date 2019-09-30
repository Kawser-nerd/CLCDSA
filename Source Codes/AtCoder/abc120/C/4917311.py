S = input()
red_count = S.count("0")
ao_count = S.count("1")
print(min(red_count, ao_count) * 2)