import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class B implements Runnable
{
	String file = "B-large";
	
	void init() throws IOException
	{
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	void solve() throws IOException
	{
		int n = nextInt(), m = nextInt();
		String[] s = new String[n];
		Map<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
		for(int i = 0; i < n; i++)
		{ 
			s[i] = next();
			String x = "";
			for(int j = 0; j < s[i].length(); j++) x += "_";
			if(!map.containsKey(x)) map.put(x, new ArrayList<String>());
			map.get(x).add(s[i]);
		}
		Map<String, ArrayList<String>> tmp = map;
		ArrayList<String> res = new ArrayList<String>();
		for(int i = 0; i < m; i++)
		{
			char[] cs = next().toCharArray();
			Map<String, Integer> cost = new HashMap<String, Integer>();
			//print(map, tmp);
			for(int j = 0; j < n; j++) cost.put(s[j], 0);
			map = tmp;
			outer: for(char c : cs)
			{
				ArrayList<String> rm = new ArrayList<String>();
				Map<String, ArrayList<String>> next = new HashMap<String, ArrayList<String>>();
				for(String ss : map.keySet())
				{
					ArrayList<String> as = map.get(ss);
					//print(ss, as);
					if(as.size() == 1)
					{ 
						rm.add(as.get(0));
						continue;
					}
					boolean ok = false;
					outer2: for(String si : as)
					{
						for(int j = 0; j < si.length(); j++)
							if(si.charAt(j) == c)
							{
								ok = true;
								break outer2;
							}
					}
					if(!ok)
					{ 
						next.put(ss, as);
						continue;
					}
					for(String si : as)
					{
						char[] bs = ss.toCharArray();
						boolean find = false;
						for(int j = 0; j < si.length(); j++)
							if(si.charAt(j) == c)
							{ 
								bs[j] = c;
								find = true;
							}
						if(!find) cost.put(si, cost.get(si) + 1);
						String sj = new String(bs);
						if(!next.containsKey(sj)) next.put(sj, new ArrayList<String>());
						next.get(sj).add(si);
					}
				}
				
				if(next.size() == 0)
				{
					int maxCost = -1;
					String ri = "";
					for(int j = 0; j < n; j++)
					{
						//print(s[j], cost.get(s[j]));
						if(maxCost < cost.get(s[j]))
						{
							maxCost = cost.get(s[j]);
							ri = s[j];
						}
					}
					res.add(ri);
					break outer;
				}
				
				map = next;
			}
		}
		
		out.print("Case #" + test + ": ");
		System.out.print("Case #" + test + ": ");
		for(int i = 0; i < res.size(); i++)
			if(i != res.size() - 1)
			{ 
				out.print(res.get(i) + " ");
				System.out.print(res.get(i) + " ");
			}
			else 
			{
				out.println(res.get(i));
				System.out.println(res.get(i) + " ");
			}
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
		new Thread(null, new B(), "", 1 << 20).start();
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