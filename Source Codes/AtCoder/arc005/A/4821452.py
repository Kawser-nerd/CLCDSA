N = int(input())
w = input().split()
w[-1] = w[-1].replace('.', '')

print(w.count("TAKAHASHIKUN") + w.count("Takahashikun") + w.count("takahashikun"))