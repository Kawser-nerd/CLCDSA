count = 0
c = input()
vowel_list = 'aiueo'
for i in range(5):
    if c == vowel_list[i]:
        count+=1
if count == 1:
    print('vowel')
else :
    print('consonant')