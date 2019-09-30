alphabet='abcdefghijklmnopqrstuvwxyz'
S=input()
def findabc():
    for i in alphabet:
    	if i not in S:return i
print(findabc())