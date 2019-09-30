def main():
    N = int(input())

    Ai_to_num = {}
    for _ in range(N):
        Ai = input()
        if Ai in Ai_to_num.keys():
            Ai_to_num[Ai] += 1
        else:
            Ai_to_num[Ai] = 1
    ct = 0
    for num_i in Ai_to_num.values():
        if num_i % 2:
            ct += 1
    
    print(ct)

main()