import sys
import math

input = sys.stdin.readline


a = input().rstrip()

vowel = ['a', 'i', 'u', 'e', 'o']
flag = False

for i in vowel:
    if (i == a):
        flag = True

if (flag == True):
    print('vowel')
else:
    print('consonant')