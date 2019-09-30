import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C
{
	static PrintWriter out = new PrintWriter(
			new BufferedOutputStream(System.out));
	static MyScanner sc = new MyScanner(System.in);
	static StringBuilder output = new StringBuilder();

	public static void main(String... args)
	{
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++)
		{
			Object result = solve();
			output.append("Case #");
			output.append(i);
			output.append(": ");
			output.append(result);
			output.append("\n");
		}

		eOP();
	}
	
	private static Object solve()
	{
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		double u = sc.nextDouble();
		
		PriorityQueue<Core> cores = new PriorityQueue<Core>();
		for (int i = 0; i < n; i++)
		{
			cores.add(new Core(sc.nextDouble()));
		}
		
		while (u > 0)
		{
			Core current = cores.poll();
			Core next = cores.poll();
			
			if (next != null)
			{
				double delta = next.p - current.p;
				double total = delta * current.num;	
				
				if (total > u)
				{
					delta = u / current.num;
					total = delta * current.num;
					current.p += delta;
					u = 0; 
					cores.add(current);
					cores.add(next);
				}
				else
				{
					next.num += current.num;
					u -= total;
					cores.add(next);
				}
			}
			else
			{
				double delta = u / current.num;
				current.p += delta;
				u = 0;
				cores.add(current);
			}
			
		}
		
		return pi(cores);
	}
	
	private static double pi(PriorityQueue<Core> queue)
	{
		Core[] cores = queue.toArray(new Core[0]);
		double result = 1;
		
		for (int i = 0; i < cores.length; i++)
		{
			result *= Math.pow(cores[i].p, cores[i].num);
		}
		
		return result;
	}

	private static class Core implements Comparable<Core>
	{
		int num;
		double p;
		
		public Core (double p)
		{
			this.p = p;
			this.num = 1;
		}
		
		@Override
		public int compareTo(Core o)
		{
			return Double.compare(this.p, o.p);
		}
		
	}

	private static void eOP()
	{
		System.out.println(output);
		System.exit(0);
	}
	
	/**
	 * Flatfoot's Scanner with slight modifications.
	 * 
	 * @author <a href="http://codeforces.com/profile/Flatfoot">Flatfoot</a>
	 * @see <a href="http://codeforces.com/blog/entry/7018">Source</a>
	 */
	private static class MyScanner
	{
		BufferedReader br;
		StringTokenizer st;

		MyScanner(InputStream in)
		{
			this.br = new BufferedReader(new InputStreamReader(in));
		}

		String next()
		{
			while (this.st == null || !this.st.hasMoreElements())
			{
				try
				{
					this.st = new StringTokenizer(this.br.readLine());
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
			}
			return this.st.nextToken();
		}

		int nextInt()
		{
			return Integer.parseInt(this.next());
		}

		long nextLong()
		{
			return Long.parseLong(this.next());
		}

		double nextDouble()
		{
			return Double.parseDouble(this.next());
		}

		/**
		 * This method has been modified to be a bit more similar to Scanner's
		 * 
		 * @author <a href=
		 *         "http://codeforces.com/profile/Flatfoot">Flatfoot</a>,
		 *         <a href=
		 *         "http://codeforces.com/profile/JasonBaby">JasonBaby</a>
		 */
		String nextLine()
		{
			if (this.st == null || !this.st.hasMoreElements())
			{
				String str = "";
				try
				{
					str = this.br.readLine();
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
				return str;
			}
			else
			{
				StringBuilder str = new StringBuilder();
				while (this.st.hasMoreElements())
				{
					str.append(this.st.nextToken());
					str.append(" ");
				}
				str.deleteCharAt(str.length() - 1);
				return str.toString();
			}
		}

	}
}
