
import static java.util.Arrays.*;
import static java.lang.Math.*;
import java.util.*;
import java.io.*;

public class Rank implements Runnable
{
	public static void main(String [] args) throws IOException
	{
		new Thread(null, new Rank(), "", 1 << 20).start();
	}
	
	String file = "C-large";
	BufferedReader input;
	PrintWriter out;
	
	public void run()
	{
		try
		{
			input = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
			
			C = new long[501][501];
			C[0][0] = 1;
			for(int i = 1; i <= 500; i++)
				for(int j = 0; j <= i; j++)
				{
					C[i][j] = C[i - 1][j] % MOD;
					if(j > 0) C[i][j] = (C[i][j] + C[i - 1][j - 1]) % MOD;
				}
			int TEST = Integer.parseInt(input.readLine());
			for(int test = 1; test <= TEST; test++)
			{
				System.out.println("Running on testcase #" + test);	
				solve(test);
			}
				
			input.close();
			out.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}
	long[][] C;
	long MOD = 100003;
	long[][] dp;
	void solve(int test) throws IOException
	{
		int n = Integer.parseInt(input.readLine());
		dp = new long[n + 1][n + 1];
		for(long[] t : dp) fill(t, -1);
		long res = 0;
		for(int i = 1; i < n; i++)
		{
			res = (res + get(n, i)) % MOD;
			//print(n, i, get(n, i));
		}
		gcj(test, res + "");
	}
	long get(int n, int k)
	{
		if(k == 1)
		{
			if(n != 1) return 1;
			return 0;
		}
		if(dp[n][k] != -1) return dp[n][k];
		
		long res = 0;
		for(int i = 1; i < k; i++) 
		{
			if(n - k - 1 >= k - i - 1)
			{
				//print(n - k - 1, k - i - 1, C[n - k - 1][k - i - 1]);
				res = (res + C[n - k - 1][k - i - 1] * get(k, i)) % MOD;
			}
		}
		//print("DEBUG", n, k, res);
		return dp[n][k] = res;
	}
	
	StringTokenizer tokens() throws IOException
	{
		return new StringTokenizer(input.readLine());
	}
	
	String next(StringTokenizer st)
	{
		return st.nextToken();
	}
	
	int nextInt() throws IOException
	{
		return Integer.parseInt(input.readLine());
	}
	
	int nextInt(StringTokenizer st)
	{
		return Integer.parseInt(st.nextToken());
	}
	
	double nextDouble() throws IOException
	{
		return Double.parseDouble(input.readLine());
	}
	
	double nextDouble(StringTokenizer st)
	{
		return Double.parseDouble(st.nextToken());
	}
	
	void print(Object... o)
	{
		System.out.println(deepToString(o));
	}
	
	void gcj(int test, String s)
	{
		out.println("Case #" + test + ": " + s);
		System.out.println("Case #" + test + ": " + s);
	}
}