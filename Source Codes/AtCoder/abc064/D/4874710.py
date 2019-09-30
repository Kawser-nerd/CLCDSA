n=int(input())
s=input()
t=s
while "()" in s:
    s=s.replace("()","")

print(s.count(")")*"("+t+")"*s.count("("))