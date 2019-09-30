/*

Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class B
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");

	private class Word
	{
		public final String text;
		public final char[] v;
		public int score;
		
		public Word(String textIn)
		{
			text = textIn;
			v = text.toCharArray();
		}
		
		public String guess(String pattern, char c)
		{
			char[] p = pattern.toCharArray();
			for(int i = 0; i < v.length; ++i) if(v[i] == c) p[i] = v[i];
			return new String(p);
		}
	}
	
	public Word[] W;
	public int Wn, Qn;
	public char[] L;
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);
			String[] pattern = new String[12];
			pattern[0] = "";
			for(int i = 1; i < pattern.length; ++i) pattern[i] = pattern[i-1] + "-";
			
			int TCase = in.nextInt();
			for(int cc = 1; cc <= TCase; ++cc)
			{
				Wn = in.nextInt();
				Qn = in.nextInt();
				
				W = new Word[Wn];
				for(int i = 0; i < Wn; ++i) W[i] = new Word(in.next());
								
				out.print("Case #" + cc + ":");
				
				for(int Qc = 0; Qc < Qn; ++Qc)
				{
					if(Qc > 0 && Qc % 10 == 0) System.err.println("Qc = " + Qc);
					
					L = in.next().toCharArray();
					
					ArrayList<Word>[] A = new ArrayList[12];					
					for(int i = 1; i < A.length; ++i)
						A[i] = new ArrayList<Word>();
					
					for(Word w : W)
					{
						A[w.text.length()].add(w);
					}
										
					for(int i = 1; i < A.length; ++i) if(A[i].size() > 0)
					{
						boolean[] S = new boolean[26];
						Arrays.fill(S, true);
						go(A[i], S, pattern[i], 0, 0);
					}
					
					int max = -1;
					String best = null;
					
					for(int x = 0; x < W.length; ++x) if(W[x].score > max)
					{
						max = W[x].score;
						best = W[x].text;
					}
					
					out.print(" " + best);
				}//ends for(int Qc = 0; Qc < Qn; ++Qc)
				
				out.println();
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()

	public void go(ArrayList<Word> A, boolean[] S, String pattern, int score, int index)
	{
		if(A.size() <= 0) return;
		if(A.size() == 1)
		{
			A.get(0).score = score;
			return;
		}
		
		boolean[] exist = new boolean[26];		
		for(Word w : A)
		{
			for(char c : w.v) exist[c-'a'] = true;
		}
		
		for(int i = 0; i < 26; ++i) S[i] = (S[i] && exist[i]);
		
		//figure out which letter is guessed next
		while(!S[L[index] - 'a']) ++index;
		
		HashMap<String, ArrayList<Word>> map = new HashMap<String, ArrayList<Word>>();
		
		for(Word w : A)
		{
			String p = w.guess(pattern, L[index]);
			
			ArrayList<Word> T;
			
			if(!map.containsKey(p))
			{
				T = new ArrayList<Word>();
				map.put(p, T);
			}
			else
			{
				T = map.get(p);
			}
			
			T.add(w);
		}
		
		for(String p : map.keySet())
		{
			ArrayList<Word> T = map.get(p);
			go(T, S.clone(), p, score + (p.equals(pattern) ? 1 : 0), index + 1);
		}
	}
	
	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new B()).main();
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
