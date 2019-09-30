s = input()

red_count = s.count('0')
blue_count = s.count('1')

print(min(red_count,blue_count) * 2)