N = int(input())

W = input()
words = set([W])
end = W[len(W)-1]

lose = "*"
for i in range(1,N):
    W = input()
    if ((W in words) or W[0] != end) and lose == "*":
        if i % 2 == 0:
            lose = "hiragana"
        else:
            lose = "katakana"
    end = W[len(W)-1]
    words.add(W)
    #print(words)
    #print(lose)

if lose == "*":
    print("DRAW")
elif lose == "katakana":
    print("WIN")
else:
    print("LOSE")