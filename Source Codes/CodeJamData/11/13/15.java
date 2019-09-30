package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Cards {

	public static void main(String[] args) throws Exception {

		BufferedReader bReader = new BufferedReader(new FileReader("c:/codejam/card-in.txt"));
		String line = bReader.readLine();

		//Number of cases
		int t = Integer.parseInt(line);

		for (int i = 0; i < t; i++) {

			int n = Integer.parseInt(bReader.readLine());
			List<Card> hand = new ArrayList<Card>();
			List<Card> deck = new ArrayList<Card>();
			for (int j = 0; j < n; j++) {
				hand.add(new Card(bReader.readLine()));
			}
			int m = Integer.parseInt(bReader.readLine());
			for (int j = 0; j < m; j++) {
				deck.add(new Card(bReader.readLine()));
			}

			int soln = solve(hand, deck, 0, 1);

			System.out.println("Case #" + (i + 1) + ": " + soln);

		}

		bReader.close();

	}

	private static int solve(List<Card> hand, List<Card> deck, int draw, int t) {

		if(t==0){
			return 0;
		}
		Collections.sort(hand);
		int score = 0;
		int c = 0;
		boolean played = false;
		Iterator<Card> it = hand.iterator();
		//play all free cards.
		while (it.hasNext()) {
			Card card = it.next();
			if (card.t > 0) {
				score += card.s;
				t += card.t - 1;
				c += card.c;
				it.remove();
				played = true;
			}
			else if (card.c > 0 && draw > 0) {
				score += card.s;
				c += card.c;
				t--;
				it.remove();
				draw--;
				played = true;
			}
		}
		if (deck.size() > 0 && !(!played && draw > 0)) {
			//add from the deck
			if (c > 0) {
				for (int j = 0; j < c && deck.size() > 0; j++) {
					hand.add(deck.remove(0));
				}
				score += solve(hand, deck, draw, t);
			}
			else {

				int additional = 0;
				Collections.sort(hand);
				for (int i = 0; i < Math.min(t, hand.size()); i++) {
					additional += hand.get(i).s;
				}

				//faff
				List<Card> handCopy = new ArrayList<Card>(hand);
				List<Card> deckCopy = new ArrayList<Card>(deck);
				score += Math.max(additional, solve(handCopy, deckCopy, 1, t));
			}
		}
		else {
			//Pick t biggest scores.
			Collections.sort(hand);
			for (int i = 0; i < Math.min(t, hand.size()); i++) {
				score += hand.get(i).s;
			}
		}
		return score;
	}

	static class Card implements Comparable<Card> {
		int s, c, t;

		public Card(String l) {
			String[] k = l.split(" ");
			c = Integer.parseInt(k[0]);
			s = Integer.parseInt(k[1]);
			t = Integer.parseInt(k[2]);
		}

		@Override
		public int compareTo(Card arg0) {
			return s > arg0.s ? -1 : s < arg0.s ? 1 : 0;
		}
	}

}
