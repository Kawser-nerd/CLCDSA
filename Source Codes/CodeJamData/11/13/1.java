import java.util.*;
public class C {
	static HashMap<String,Integer> H;
	static String list;
	static int [][] signatures;
	static boolean flag2 = true;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			int N = sc.nextInt();
			ArrayList<Card> Hand = new ArrayList<Card>();
			for (int i = 0; i<N; ++i) Hand.add(  new Card (sc.nextInt(), sc.nextInt(), sc.nextInt())); 
			int M = sc.nextInt();
			LinkedList<Card> Deck = new LinkedList<Card>();
			for (int i = 0; i<M; ++i) Deck.add(  new Card (sc.nextInt(), sc.nextInt(), sc.nextInt())); 
			int ans = recurse(Hand,Deck, 1);
			
			System.out.printf("Case #%d: %s\n",ii, ans);
		}
		
	}
	static int recurse (ArrayList<Card> Hand, LinkedList<Card> Deck, int turns) {
		if (turns == 0 || Hand.size() == 0) return 0;
		Iterator<Card> Ic = Hand.iterator();
		int score = 0;
		ArrayList<Card> Hand2 = new ArrayList<Card>();
		boolean flag = false;
		while (Ic.hasNext()) {
				Card c = Ic.next();
				if (c.t > 0) {
					Ic.remove();
					score += c.s;
					turns += c.t;
					turns--;
					while (Deck.size() > 0 && c.c > 0) {
						Hand2.add(Deck.removeFirst());
						c.c--;
					}
					flag = true;
				}
		}
		if (flag) {
			Hand.addAll(Hand2);
			return score+recurse(Hand, Deck, turns);
		}
		flag2 = true;
		Collections.sort(Hand);
		int best = 0;
		for (int i = 0; i<turns && i < Hand.size(); ++i) best += Hand.get(i).s;
		flag2 = false;
		Collections.sort(Hand);
		flag2 = true;
		if (Hand.size() > 0) {
			Card c = Hand.remove(0);
			score += c.s;
			turns += c.t;
			turns--;
			while (Deck.size() > 0 && c.c > 0) {
				Hand.add(Deck.removeFirst());
				c.c--;
			}
		}
		best = Math.max(score+recurse(Hand, Deck, turns), best);
		return best;
	}
	static class Card implements Comparable<Card>{
		int c,s,t;
		public Card (int c, int s, int t) {
			this.c = c;
			this.s = s;
			this.t = t;
		}
		public int compareTo (Card cr) {
			return (flag2 || cr.c == c) ? cr.s -s  : cr.c - c;
		}
	}
}