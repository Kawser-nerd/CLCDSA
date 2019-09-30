import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class A implements Runnable
{
	String file = "A-large";
	
	void init() throws IOException
	{
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	void solve() throws IOException
	{
		long n = nextLong();
		int pd = nextInt();
		int pg = nextInt();
		
		if(pg == 100)
		{
			if(pd < 100) 
			{
				gcj("Broken");
				return;
			}
		}
		if(pg == 0)
		{
			if(pd > 0)
			{
				gcj("Broken");
				return;
			}
		}
		for(int d = 1; d <= 100; d++)
		{
			int x = d * pd;
			//print(x, n);
			if(x % 100 == 0)
			{
				if(d <= n)
				{
					gcj("Possible");
					return;
				}
			}
		}
		gcj("Broken");
	}
	
	String next() throws IOException
	{
		while(tokenizer == null || !tokenizer.hasMoreTokens()) tokenizer = new StringTokenizer(input.readLine());
		return tokenizer.nextToken();
	}
	
	int nextInt() throws IOException
	{
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException
	{
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException
	{
		return Double.parseDouble(next());
	}
	
	void print(Object... o)
	{
		System.out.println(deepToString(o));
	}
	
	void gcj(Object o)
	{
		String s = String.valueOf(o);
		out.println("Case #" + test + ": " + s);
		System.out.println("Case #" + test + ": " + s);
	}
	
	BufferedReader input;
	PrintWriter out;
	StringTokenizer tokenizer;
	int test;
	
	public static void main(String[] args) throws IOException
	{
		new Thread(null, new A(), "", 1 << 20).start();
	}
	
	public void run()
	{
		try
		{
			init();
			int TEST = nextInt();
			for(test = 1; test <= TEST; test++)
			{
				System.out.println("Running on testcase #" + test);	
				solve();
			}	
			out.close();		
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}
}