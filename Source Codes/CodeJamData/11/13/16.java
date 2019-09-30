package Round1A.ProblemC;


import sun.misc.Sort;

import javax.swing.text.JTextComponent;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class C {

    public static final File input = new File("C:\\Users\\Dell\\Downloads\\C-small-attempt1.in");
    public static final File output = new File("D:\\IdeaProjects\\CodeJam2011\\src\\Round1A\\ProblemC\\output.txt");

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(input);
        BufferedWriter out = new BufferedWriter(new FileWriter(output));

        int T = scanner.nextInt(); // 1 ≤ T ≤ 100

        for (int test = 1; test <= T; test++) {
            int N = scanner.nextInt(); // 1 ≤ N

            List<Card> hand = new ArrayList<Card>(N);
            int id = 0;
            for (int h = 0; h < N; h++) {
                Card card = new Card();
                card.id = ++id;
                card.c = scanner.nextInt();
                card.s = scanner.nextInt();
                card.t = scanner.nextInt();

                hand.add(card);
            }


            int M = scanner.nextInt(); // 0 ≤ M, N + M ≤ 80
            List<Card> deck = new ArrayList<Card>(M);
            for (int d = 0; d < M; d++) {
                Card card = new Card();
                card.id = ++id;
                card.c = scanner.nextInt();
                card.s = scanner.nextInt();
                card.t = scanner.nextInt();

                deck.add(card);
            }

            Collections.reverse(deck);
            int res = solve(0, 1, hand, deck);
            out.append("Case #" + test + ": " + res + "\n");
        }

        out.flush();
        out.close();

    }

    private static int solve(int current_sum, int rest_of_turns, List<Card> hand, List<Card> deck) {
//        System.out.println("turns: " + rest_of_turns + ", bonus:" + current_sum);
//        System.out.println(hand);
//        System.out.println(deck);
//        System.out.println();

        if (rest_of_turns == 0 || hand.isEmpty()) {
            return current_sum;
        }

        boolean cardDropped = false;
        for (int i = 0; i < hand.size(); i++) {
            Card card = hand.get(i);
            if (card.t > 0) {
                hand.remove(i);  // drop card
                cardDropped = true;
                i--;

                current_sum += card.s; // bonus
                rest_of_turns += card.t - 1; // turns

                int cards_to_take = Math.min(card.c, deck.size()); // more cards
                while (cards_to_take > 0) {
                    hand.add(deck.remove(deck.size() - 1));
                    cards_to_take--;
                }
            }
        }

        if (cardDropped) {
            return solve(current_sum, rest_of_turns, hand, deck); // will check for empty set of cards in the hand... etc
        }


        // -- Now card.t == 0 for all cards in hand.

        if (deck.isEmpty()) {
            // -- card.c can be ignored. let's drop cards with max S.

            ArrayList<Card> sorted = new ArrayList<Card>(hand);  // copy of hand to keep relative order...
            Collections.sort(sorted, new Comparator<Card>() {
                @Override
                public int compare(Card o1, Card o2) {
                    return o1.s - o2.s;
                }
            });

            int amount = Math.min(rest_of_turns, sorted.size());
            while (amount > 0) {
                amount--;
                rest_of_turns--;
                Card card_with_max_s = sorted.remove(sorted.size() - 1);
                current_sum += card_with_max_s.s;
            }

            return solve(current_sum, rest_of_turns, sorted, deck);
        }

        // we have hand.size() possible moves here.
        // let's check it ...

        int bestResult = current_sum;

        // we have 2 variants:
        // take card with max c and s
        // or take card with max s and c.
        // if it is the same card, we have only one variant...

        // update max sum by c.
        Card[] maxS = {null, null, null};// c=0, c=1, c=2.

        for (int i = 0; i < hand.size(); i++) {
            Card c = hand.get(i);
            Card card = maxS[c.c];
            if (card == null || card.s < c.s) {
                maxS[c.c] = c;
            }
        }


        for (Card card : maxS) {
            if (card == null) {
                continue;
            }

            ArrayList<Card> h = new ArrayList<Card>(hand);
            ArrayList<Card> d = new ArrayList<Card>(deck);

            // do move ...

            h.remove(card);

            int current_sum2 = current_sum + card.s;      // bonus
            int rest_of_turns2 = rest_of_turns + card.t - 1;     // turns

            int cards_to_take = Math.min(card.c, d.size()); // more cards
            while (cards_to_take > 0) {
                h.add(d.remove(d.size() - 1));
                cards_to_take--;
            }

            int result = solve(current_sum2, rest_of_turns2, h, d);
            bestResult = Math.max(bestResult, result);
        }

        return bestResult;
    }


    static class Card {
        int id;
        int c;  // 0..2
        int s;  // 0..50
        int t;  // 0..50

        public String toString() {
            return "Card[" + id + "](" + c + ", " + s + ", " + t + ")";
        }
    }
}

/*
Limits

1 ≤ T ≤ 100.
1 ≤ N.
0 ≤ M.
N + M ≤ 80.
Small dataset

0 ≤ c ≤ 1.
0 ≤ s ≤ 20.
0 ≤ t ≤ 20.
Large dataset

0 ≤ c ≤ 2.
0 ≤ s ≤ 50.
0 ≤ t ≤ 50.
*/