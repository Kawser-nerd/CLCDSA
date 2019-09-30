s = input()
length = len(s)
for i in range(1,length):
    if s[:length//2-i] == s[length//2-i:length-i*2]:
        print((length//2-i) * 2)
        break