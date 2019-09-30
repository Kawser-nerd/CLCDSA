S = input()
red_count = S.count("0")
ao_count = S.count("1")
if red_count > ao_count:
    print(ao_count * 2)
elif red_count < ao_count:
    print(red_count * 2)
else:
    print(red_count + ao_count)