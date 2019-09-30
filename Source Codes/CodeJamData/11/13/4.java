import java.util.*;

public class C
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for(int ca=0;ca < T;ca++)
		{
			int n = scan.nextInt();

			ArrayList<Card> hand = new ArrayList<Card>();
			Queue<Card> deck = new LinkedList<Card>();

			for(int i=0;i < n;i++)
				hand.add(new Card(scan.nextInt(), scan.nextInt(), scan.nextInt()));

			int m = scan.nextInt();
			for(int i=0;i < m;i++)
				deck.offer(new Card(scan.nextInt(), scan.nextInt(), scan.nextInt()));



			//PLAY DOMINION! WOOOOOO!
			int turns = 1;
			int score = 0;

			int bestscore = 0;
			
			while(turns > 0 && hand.size() > 0)
			{
				//System.out.println("Turns left: " + turns);
				//Look for free turns
				for(int i=0;i < hand.size();i++)
				{
					Card c = hand.get(i);
					if(c.t > 0)
					{
						turns += c.t - 1;
						score += c.s;
						while(c.c > 0 && !deck.isEmpty())
						{
							hand.add(deck.poll());
							c.c--;
						}
						hand.remove(i);
						i--;
						//System.out.println("Playing " + c);
					}
					
				}

				if(hand.size() == 0)
					break;

				//If we can play everything, then play anything
				if(turns >= hand.size())
				{
					Card c = hand.get(0);
					turns += c.t;
					score += c.s;
					while(c.c > 0 && !deck.isEmpty())
					{
						hand.add(deck.poll());
						c.c--;
					}
					hand.remove(0);
					turns--;
					//System.out.println("Playing " + c);
					continue;
				}

				//Count number of cards that are worth more cards
				//Find one with highest score
				int idx = -1;
				int best = -1;
				int count = 0;

				for(int i=0;i < hand.size();i++)
				{
					Card c = hand.get(i);
					if(c.c > 0)
					{
						count++;
						if(c.s > best)
						{
							best = c.s;
							idx = i;
						}
					}
				}

				if(idx >= 0 && turns > hand.size() - count)
				{
					Card c = hand.get(idx);
					turns += c.t;
					score += c.s;
					while(c.c > 0 && !deck.isEmpty())
					{
						hand.add(deck.poll());
						c.c--;
					}
					hand.remove(idx);
					turns--;
					//System.out.println("Playing " + c);
					continue;
				}

				//What if we didn't draw any more cards?
				Collections.sort(hand);
				int hypo = 0;

				for(int i=0;i < turns;i++)
				{
					hypo += hand.get(i).s;
					bestscore = Math.max(bestscore, score+hypo);
				}

				//Otherwise, do that other thing again
				idx = -1;
				best = -1;

				for(int i=0;i < hand.size();i++)
				{
					Card c = hand.get(i);
					if(c.c > 0)
					{
						count++;
						if(c.s > best)
						{
							best = c.s;
							idx = i;
						}
					}
				}

				if(idx >= 0)
				{
					Card c = hand.get(idx);
					turns += c.t;
					score += c.s;
					while(c.c > 0 && !deck.isEmpty())
					{
						hand.add(deck.poll());
						c.c--;
					}
					hand.remove(idx);
					//System.out.println("Playing " + c);
				}

				

				turns--;
			}

			bestscore = Math.max(score, bestscore);
			System.out.println("Case #" + (ca+1) + ": " + bestscore);
		}


	}

	
}

class Card implements Comparable
{
	int c, s, t;

	public Card(int ic, int is, int it)
	{
		c = ic;
		s = is;
		t = it;
	}

	public int compareTo(Object o)
	{
		Card that = (Card)o;

		return that.s - this.s;
	}

	public String toString()
	{
		return "(" + c + "," + s + "," + t + ")";
	}
}