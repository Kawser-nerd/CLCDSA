package round1a;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class C {
	
	int caseNo;
	
	class Card {
		int cards, score, turns;
		
		void read(Scanner in) {
			cards = in.nextInt();
			score = in.nextInt();
			turns = in.nextInt();
		}
	}
	
	int getBestScore(ArrayList<Card> cards, int handSize, int num) {
		
		int[] a = new int[handSize];
		
		for (int i = 0; i < handSize; i++) {
			a[i] = cards.get(i).score;
		}
		
		Arrays.sort(a);
		num = Math.min(num, handSize);
		
		
		int score = 0;
		
		for (int i = 0; i < num; i++) {
			score += a[handSize - i - 1];
		}
		
		
		
		return score;
	}
	
	Card getTurnCard(ArrayList<Card> cards, int numHand) {
		for (int i = 0; i < numHand ;i++) {
			if (cards.get(i).turns > 0) return cards.get(i);
		}
		
		return null;
	}
	
	public void test(Scanner in) {
		
		ArrayList<Card> cards = new ArrayList<C.Card>();
		
		int n = in.nextInt();
		
		//read n hand cards
		for (int i=0;i<n;i++) {
			Card c = new Card();
			c.read(in);
			cards.add(c);
		}
		
		int m = in.nextInt();
		
		//read m deck cards
		for (int i=0;i<m;i++) {
			Card c = new Card();
			c.read(in);
			cards.add(c);
		}
		
		
		int turns = 1;
		int maxScore = 0;
		//
		
		int curScore = 0;
		int cardsInHand = n;
		while (turns > 0 && cardsInHand > 0) {
			
			//calc best possible score in hand (max [turn] scores)
			int bestScore = getBestScore(cards, cardsInHand, turns);
			bestScore += curScore;
			if (bestScore > maxScore) maxScore = bestScore;
			
			//if you get more turns play them
			Card c = getTurnCard(cards, cardsInHand);
			if (c != null) {
				//play c
				
				turns --;
				cards.remove(c);
				cardsInHand --;
				
				curScore += c.score;
				turns += c.turns;
				cardsInHand += c.cards;
				cardsInHand = Math.min(cardsInHand, cards.size());
				
				
				continue;
			}
			
			//otherwise play acqCard with highest score
			c = getAcqCardWithHighestScore(cards, cardsInHand);
			if (c != null) {
				//play c
				
				turns --;
				cards.remove(c);
				cardsInHand --;
				
				curScore += c.score;
				turns += c.turns;
				cardsInHand += c.cards;
				cardsInHand = Math.min(cardsInHand, cards.size());
				
				
				continue;
			}
			
			
			//otherwise you are done
			break;
			
			
		}
		
		
		

		System.out.println("Case #"  + caseNo + ": " + maxScore);
		
	}
	
	

	private Card getAcqCardWithHighestScore(ArrayList<Card> cards, int cardsInHand) {
		int bestScore = 0;
		
		Card bestCard = null;
		for (int i = 0; i < cardsInHand; i++) {
			Card c = cards.get(i);
			if (c.cards > 0 && c.score > bestScore) {
				bestScore = c.score;
				bestCard = c;
			}
		}
		
		
		
		return bestCard;
	}

	public static void main(String[] args) throws Exception{
	
		System.setOut(new PrintStream(new File("c.out")));
		(new C()).test();
		
	}

	public void test() throws Exception{

		Scanner s = new Scanner(new File("C-small-attempt0.in"));

		int numTests = s.nextInt();

		for (caseNo = 1; caseNo <= numTests; caseNo++) {
			test(s);
		}

	}
}
