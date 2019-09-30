c=0
for i in range(int(input())):
    s=input()
    c+=s.count("R")-s.count("B")
print("DRAW"if c==0 else("AOKI" if c<0 else"TAKAHASHI"))