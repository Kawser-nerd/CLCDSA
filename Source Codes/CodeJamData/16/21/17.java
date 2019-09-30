package codeJamRound1B;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A {

	
	public static void main(String[] args) throws IOException 
	{
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("problem_A.out"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		char[] s = new char[] { 'Z', 'W', 'U', 'F', 'X', 'O', 'R', 'V', 'G', 'N'};
		String[] words = new String[] { "ZERO", "TWO", "FOUR", "FIVE", "SIX", "ONE",  "THREE",  "SEVEN", "EIGHT", "NINE"};
		int[] a = new int[] {0, 2, 4, 5, 6, 1, 3, 7, 8, 9};
		int tc = sc.nextInt();
		for(int t = 1; t <= tc; ++t)
		{
			int[] ans = new int[10];
			
			int[] f = new int[26];
			String line = sc.next();
			for(int i = 0; i < line.length(); ++i)
				f[line.charAt(i)-'A']++;
			for(int i = 0; i < 10; ++i)
				while(f[s[i]-'A'] > 0)
				{
				
					ans[a[i]]++;
					remove(f, words[i]);
				}
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < 10; ++i)
				while(ans[i]-->0)
					sb.append(i);
			out.printf("Case #%d: %s\n", t, sb.toString());
		}
		out.flush();
		out.close();

	}
	
	static void remove(int[] f, String w)
	{
		for(int i = 0; i < w.length(); ++i)
			f[w.charAt(i)-'A']--;
	}

	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}
		
		public Scanner(FileReader r){	br = new BufferedReader(r);}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}

		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}

		public double nextDouble() throws IOException
		{
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if(x.charAt(0) == '-')
			{
				neg = true;
				start++;
			}
			for(int i = start; i < x.length(); i++)
				if(x.charAt(i) == '.')
				{
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				}
				else
				{
					sb.append(x.charAt(i));
					if(dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg?-1:1);
		}

		public boolean ready() throws IOException {return br.ready();}


	}
}