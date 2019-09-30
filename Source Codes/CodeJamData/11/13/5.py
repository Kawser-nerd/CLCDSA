def solve(hand, deck, score, turns):
    if not hand or turns == 0:
        return score
    hand.sort()
    t, c, s = hand[-1]
    if t > 0:
        hand.pop()
        turns += t - 1
        score += s
        if c and deck:
            hand.append(deck.pop())
        return solve(hand, deck, score, turns)
    else:
        score0 = score
        for i, card in enumerate(hand):
            t, c, s = card
            if c == 1:
                for t, c, s in hand[i - turns: i]:
                    score0 += s
                break
        t, c, s = hand.pop()
        turns -= 1
        score += s
        if c and deck:
            hand.append(deck.pop())
        score1 = solve(hand, deck, score, turns)
        return max(score0, score1)

def main():
    T = int(input())
    for i in range(1, T + 1):
        N = int(input())
        hand = []
        for j in range(N):
            c, s, t = map(int, input().split())
            hand.append((t, c, s))
        M = int(input())
        deck = []
        for j in range(M):
            c, s, t = map(int, input().split())
            deck.append((t, c, s))
        deck.reverse()
        ans = solve(hand, deck, 0, 1)
        print('Case #%d: %s' % (i, ans))

if __name__ == '__main__':
    main()

