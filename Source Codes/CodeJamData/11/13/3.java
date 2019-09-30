/*

Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");

	public int nextID = 1;
	
	private class Card implements Comparable<Card>
	{
		public int c, s, t;
		public int ID;
		
		public Card(int cIn, int sIn, int tIn)
		{
			c = cIn; s = sIn; t = tIn;
			ID = nextID++;
		}
		
		public int compareTo(Card u)
		{
			if(t != u.t) return -(t - u.t);
			if(c != u.c) return -(c - u.c);
			if(s != u.s) return -(s - u.s);
			return ID - u.ID;
		}
		
		public String toString() { return "(" + c + ", " + s + ", " + t + ")"; }
	}
	
	public TreeSet<Card>[] C;
	public ArrayList<Card> hand;
	public ArrayList<Card> deck;
	public int Dn, Hn;
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);

			int TCase = in.nextInt();
			for(int cc = 1; cc <= TCase; ++cc)
			{
				Hn = in.nextInt();
				hand = new ArrayList<Card>();
				for(int i = 0; i < Hn; ++i) hand.add(new Card(in.nextInt(), in.nextInt(), in.nextInt()));
				
				Dn = in.nextInt();
				deck = new ArrayList<Card>();
				for(int i = 0; i < Dn; ++i) deck.add(new Card(in.nextInt(), in.nextInt(), in.nextInt()));
				
				int best = 0;
				for(int draw = 0; draw <= Dn; ++draw)
				{
					best = Math.max(best, play(draw));
				}
				
				out.println("Case #" + cc + ": " + best);
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()

	public int play(int draw)
	{
		int score = 0;
		int index = 0;
		int card = 0;
		int turn = 1;
		
		C = new TreeSet[3];
		for(int i = 0; i <= 2; ++i) C[i] = new TreeSet<Card>();
		
		ArrayList<Card> A = (ArrayList<Card>)hand.clone();
		int head = 0;
		
		while(turn > 0)
		{
			if(head < A.size())
			{
				Card c = A.get(head);
				++head;
				
				if(c.t >= 1)
				{
					//Play Card c
					//System.err.println("Play " + c);
					
					turn += (c.t - 1);
					score += c.s;
					
					for(int i = 0; i < c.c; ++i)
					{
						if(index < deck.size())
						{
							A.add(deck.get(index));
							++index;
						}
					}
				}
				else
				{
					//c.t == 0, partition base on c.c
					C[c.c].add(c);
				}
			}
			else
			{
				if(C[0].isEmpty() && C[1].isEmpty() && C[2].isEmpty()) break;
				//System.err.println("Picking from special cards.");
				
				Card c = null;
				if(index >= draw || C[1].isEmpty())
				{
					//Play best card
					if(!C[0].isEmpty()) c = C[0].first();
					if(!C[1].isEmpty()) c = better(c, C[1].first());
					if(!C[2].isEmpty()) c = better(c, C[2].first());					
				}
				else if(!C[2].isEmpty() && draw >= 2)
				{
				}
				else
				{
					//Play best in C[1]
					c = C[1].first();
				}
				
				//Play c
				//System.err.println("Playing " + c);
				C[0].remove(c);
				C[1].remove(c);
				C[2].remove(c);
				
				--card;
				turn += (c.t - 1);
				score += c.s;
				
				for(int i = 0; i < c.c; ++i)
				{
					if(index < deck.size())
					{
						A.add(deck.get(index));
						++index;
					}
				}
			}
		}
		
		//System.err.println("draw = " + draw + ", score = " + score);
		return score;
	}//ends public int play(int draw)
	
	public Card better(Card A, Card B)
	{
		if(A == null) return B;
		if(B == null) return A;
		
		if(A.s > B.s) return A;
		if(B.s > A.s) return B;
		
		if(A.c > B.c) return A;
		if(A.c < B.c) return B;
		
		return A;
	}
	
	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new C()).main();
		long endTime = System.currentTimeMillis();

		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}

	public int    iInt()   { return in.nextInt(); }
	public long   iLong()  { return in.nextLong(); }
	public String iToken() { return in.next(); }
	public String iLine()  { return in.nextLine(); }
}//ends public class ???
