s,a,b=input(),"",["a","i","u","e","o"]
for i in s:a+=(""if i in b else i)
print(a)