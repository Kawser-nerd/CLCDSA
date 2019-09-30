
import static java.util.Arrays.*;
import static java.lang.Math.*;
import java.util.*;
import java.io.*;

public class File implements Runnable
{
	public static void main(String [] args) throws IOException
	{
		new Thread(null, new File(), "", 1 << 20).start();
	}
	
	String file = "A-large";
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
	HashSet<String> set;
	void solve(int test) throws IOException
	{
		StringTokenizer st = tokens();
		int n = nextInt(st), m = nextInt(st);
		set = new HashSet<String>();
		set.add("/");
		for(int i = 0; i < n; i++)
		{
			String s = input.readLine();
			add(s);
		}
		int res = 0;
		for(int i = 0; i < m; i++)
		{
			String s = input.readLine();
			res += find(s);
		}
		gcj(test, res + "");
		
	}
	void add(String s)
	{
		if(s.length() == 0) return;
		set.add(s);
		add(s.substring(0, s.lastIndexOf("/")));
	}
	int find(String s)
	{
		if(s.length() == 0) return 0;
		print("B", s);
		if(set.contains(s)) return 0;
		set.add(s);
		return 1 + find(s.substring(0, s.lastIndexOf("/")));
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