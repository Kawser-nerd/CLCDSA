# coding: utf-8

N = int(input())
input_Blue = [input() for i in range(N)]

M = int(input())
input_Red = [input() for j in range(M)]

dict_Blue = {}
for str_Blue in input_Blue:
  dict_Blue[str_Blue] = dict_Blue.get(str_Blue,0) + 1

dict_Red = {}
for str_Red in input_Red:
  dict_Red[str_Red] = dict_Red.get(str_Red,0) + 1

for Blue_Key in dict_Blue.keys():
    if Blue_Key in dict_Red.keys():
      dict_Blue[Blue_Key] = dict_Blue[Blue_Key] - dict_Red[Blue_Key]

if max(dict_Blue.values()) < 0 :
       print(0)
else:
       print(max(dict_Blue.values()))