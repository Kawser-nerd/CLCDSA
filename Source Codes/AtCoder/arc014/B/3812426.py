N = int(input())
W = [input() for _ in range(N)]

words = [W[0]]
turn = 0
for w in W[1:]:
    # print(turn, w, words)
    if w in words or w[0] != words[-1][-1]:
        print(["WIN", "LOSE"][turn%2])
        exit()
    words.append(w)
    turn += 1

print("DRAW")