
import static java.util.Arrays.*;
import static java.lang.Math.*;
import java.util.*;
import java.io.*;

public class Chick implements Runnable
{
	public static void main(String [] args) throws IOException
	{
		new Thread(null, new Chick(), "", 1 << 20).start();
	}
	
	String file = "B-large";
	BufferedReader input;
	PrintWriter out;
	
	public void run()
	{
		try
		{
			input = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
			
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
	
	void solve(int test) throws IOException
	{
		StringTokenizer st = tokens();
		int N = nextInt(st), K = nextInt(st), B = nextInt(st), T = nextInt(st);
		int[] x = new int[N];
		int[] v = new int[N];
		boolean[] can = new boolean[N];
		st = tokens();
		for(int i = 0; i < N; i++) x[i] = nextInt(st);
		st = tokens();
		for(int i = 0; i < N; i++) v[i] = nextInt(st);
		for(int i = 0; i < N; i++)
		{
			if((B - x[i]) <= v[i] * T) can[i] = true;
		}
		int k = 0;
		int front = 0;
		int res = 0;
		for(int i = N - 1; i >= 0; i--)
		{
			if(k >= K) break;
			if(can[i]) 
			{
				k++;
				res += front;
			}
			else
				front++;
		}
		if(k < K) gcj(test, "IMPOSSIBLE");
		else gcj(test, res + "");
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