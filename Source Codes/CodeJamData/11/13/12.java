import java.util.*;


public class Main {
	
	static PriorityQueue<Card> hand;
	static List<Card> initialDeck;
	static int deckI;
	static int score = 0;
	static int y0 = 0;
	static int y1 = 0;
	static int y2 = 0;
	static int nTurns = 1;
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int nCases = s.nextInt();
		for (int caseN = 1; caseN <= nCases; caseN++) {
			int n = s.nextInt();
			List<Card> initialHand = new ArrayList<Card>();
			for (int i = 0; i < n; i++) {
				initialHand.add(readCard(s));
			}
			
			int m = s.nextInt();
			initialDeck = new ArrayList<Card>();
			for (int i = 0; i < m; i++) {
				initialDeck.add(readCard(s));
			}
			
			List<Card> allCards = new ArrayList<Card>(initialHand);
			allCards.addAll(initialDeck);
			//int maxX0 = maxX(allCards, 0);
			int maxX1 = maxX(allCards, 1);
			int maxX2 = maxX(allCards, 2);
			
			int bestScore = 0;
			for (int x2 = 0; x2 <= maxX2; x2++) {
				for (int x1 = 0; x1 <= maxX1; x1++) {
					hand = new PriorityQueue<Card>(initialHand);
					deckI = 0;
					score = 0;
					y0 = 0;
					y1 = 0;
					y2 = 0;
					nTurns = 1;
					while (nTurns > 0 && ! hand.isEmpty()) {
						Card top = hand.peek();
						if (top.t > 0) {
							playCard(hand.poll());
						} else if (top.c == 2) {
							if (y2 < x2) {
								playCard(hand.poll());
								y2++;
							} else {
								hand.poll();//ignore this card
							}
						} else if (top.c == 1) {
							if (y1 < x1) {
								playCard(hand.poll());
								y1++;
							} else {
								hand.poll();//ignore this card
							}
						} else /*top.c == 0 */ {
							playCard(hand.poll());
						}
					}
					bestScore = Math.max(score, bestScore);
				}
			}
			
			System.out.println("Case #" + caseN + ": " +  bestScore);
		}
	}
	static void playCard(Card card) {
		//System.out.println("Playing card " + card);
		score += card.s;
		nTurns--;
		nTurns += card.t;
		for (int i = 0; i < card.c; i++) {
			if (deckI < initialDeck.size()) {
				hand.add(initialDeck.get(deckI));
				deckI++;
			}
		}
		//System.out.println("hand = " + hand);
		//System.out.println("score = " + score + " nTurns=" + nTurns);
	}
	
	static int maxX(List<Card> cards, int c) {
		int result = 0;
		for (Card card : cards) {
			if (card.c == c && card.t == 0) {
				result++;
			}
		}
		return result;
	}
	
	static Card readCard(Scanner scan) {
		int c = scan.nextInt();
		int s = scan.nextInt();
		int t = scan.nextInt();
		return new Card(c, s, t);
	}
	static class Card implements Comparable<Card> {
		public int c, s, t;
		public Card(int c, int s, int t) {
			this.c = c;
			this.s = s;
			this.t = t;
		}
		public boolean equals(Card o) {
			return c == o.c && s == o.s && t == o.t;
		}
		public int oldCompareTo(Card o) {
			if (t != o.t) 
				return new Integer(t).compareTo(o.t);
			else if (c != o.c) 
				return new Integer(c).compareTo(o.c);
			else  
				return new Integer(s).compareTo(o.s);
		}
		
		public int compareTo(Card o) {
			return -this.oldCompareTo(o);
		}
		
		public String toString() {
			return "[c=" + c + ", t=" + t + ", s=" + s + "]";
		}
	}
}
