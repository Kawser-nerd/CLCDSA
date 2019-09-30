H,W=map(int,input().split())
joubu=["#" for i in range(W+2)]
print("".join(joubu))
for i in range(H):
    S=input()
    print("#"+S+"#")
print("".join(joubu))