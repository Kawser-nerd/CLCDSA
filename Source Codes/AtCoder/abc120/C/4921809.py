S=input()
a=S.count("0")
b=S.count("1")
print(len(S)-abs(a-b))