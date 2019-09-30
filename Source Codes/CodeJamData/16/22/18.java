package codeJamRound1B;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class B {

	static Long[][] memo;
	
	static char[] C, J;
	static int len;
	static long[] factor;
	
	static long dp(int idx, int winner)
	{
		if(idx == len)
			return 0;
		if(memo[idx][winner] != null)
			return memo[idx][winner];
		
		long ret = (long)2e18;
		for(int i = 0; i < 10; ++i)
		{
			int cVal = C[idx] == '?' ? i : (C[idx]-'0');
			for(int j = 0; j < 10; ++j)
			{
				int jVal = J[idx] == '?' ? j : (J[idx]-'0');
				if(winner == 1 || cVal >= jVal)
				{			
					ret = Math.min(ret, (cVal-jVal) * (factor[len-idx-1]) + dp(idx+1, cVal > jVal ? 1 : winner));
				}
			}
		}
		return memo[idx][winner] = ret;		
	}
	
	static long num1, num2;
	
	static void print1(int idx, int winner)
	{
		if(idx == len)
			return;
		
		long optimal = dp(idx, winner);
		for(int i = 0; i < 10; ++i)
		{
			int cVal = C[idx] == '?' ? i : (C[idx]-'0');
			for(int j = 0; j < 10; ++j)
			{
				int jVal = J[idx] == '?' ? j : (J[idx]-'0');
				if(winner == 1 || cVal >= jVal)
				{			
					if((cVal-jVal) * (factor[len-idx-1]) + dp(idx+1, cVal > jVal ? 1 : winner) == optimal)
					{
						num1 += cVal * (factor[len-idx-1]);
						num2 += jVal * (factor[len-idx-1]);
						print1(idx+1, cVal > jVal ? 1 : winner);
						return;
					}
				}
			}
		}	
	}
	
	static void print2(int idx, int winner)
	{
		if(idx == len)
			return;
		
		long optimal = dp(idx, winner);
		for(int j = 0; j < 10; ++j)
		{
			int jVal = J[idx] == '?' ? j : (J[idx]-'0');
			for(int i = 0; i < 10; ++i)
			{
				int cVal = C[idx] == '?' ? i : (C[idx]-'0');
				if(winner == 1 || cVal >= jVal)
				{			
					if((cVal-jVal) * (factor[len-idx-1]) + dp(idx+1, cVal > jVal ? 1 : winner) == optimal)
					{
						num1 += cVal * (factor[len-idx-1]);
						num2 += jVal * (factor[len-idx-1]);
						print2(idx+1, cVal > jVal ? 1 : winner);
						return;
					}
				}
			}
		}	
	}
	
	static long[] compute(char[] s1, char[] s2, int printFunct)
	{
//		System.out.println(dp(0, 0));
		len = s1.length;
		C = s1; J = s2;
		num1 = 0; num2 = 0;
		memo = new Long[len][2];
		if(printFunct == 1)
			print1(0, 0);
		else
			print2(0, 0);
//		System.out.println(dp(0, 0));
		return new long[] { dp(0, 0), num1, num2 };
	}
	
	public static void main(String[] args) throws IOException 
	{
		Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("problem_B.out"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		factor = new long[18];
		factor[0] = 1;
		for(int i = 1; i < 18; ++i)
			factor[i] = factor[i-1] * 10;
		int tc = sc.nextInt();
		for(int t = 1; t <= tc; ++t)
		{
			char[] s1 = sc.next().toCharArray();
			char[] s2 = sc.next().toCharArray();
			long[] val1 = compute(s1, s2, 1), val2 = compute(s2, s1, 2);
			if(val2[0] < val1[0] || val2[0] == val1[0] && val2[1] < val1[1] || val2[0] == val1[0] && val2[1] == val1[1] && val2[2] < val1[2])
			{
				val1[1] = val2[2];
				val1[2] = val2[1];
			}
			
			out.printf("Case #%d: %0"+len+"d %0"+len+"d\n", t, val1[1], val1[2]);
		}
		out.flush();
		out.close();

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