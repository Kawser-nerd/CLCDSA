import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A
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
		
		Pancake[] pancakes = new Pancake[n];
		
		for (int i = 0; i < n; i++)
		{
			pancakes[i] = new Pancake(sc.nextInt(), sc.nextInt());
		}
		
		Arrays.sort(pancakes);
		
		Pancake[] use = new Pancake[k];
		for (int i = 0; i < k; i++)
		{
			use[i] = pancakes[n - k + i];
		}
		
		int minI = 0;
		int maxI = 0;
		
		for (int i = 0; i < k; i++)
		{
			if (use[i].rH() < use[minI].rH())
			{
				minI = i;
			}
			if (use[i].r > use[maxI].r)
			{
				maxI = i;
			}
		}
		
		int bestI = 0;
		long improvement = 0;
		
		for (int i = 0; i < n - k; i++)
		{
			long improv = pancakes[i].total() - 2 * use[minI].rH() - use[maxI].r2();
			if (improv > improvement)
			{
				bestI = i;
				improvement = improv;
			}
		}
		
		if (improvement > 0)
		{
			use[minI] = pancakes[bestI]; 
		}
		
		return resultOf(use);
	}
	
	private static double resultOf(Pancake[] use)
	{
		int bestR = 0;
		long total = 0;
		for (int i = 0; i < use.length; i++)
		{
			if (use[i].r > bestR)
			{
				bestR = use[i].r;
			}
			
			total += use[i].rH();
		}
		total <<= 1;
		total += ((long)bestR) * bestR;
		
		return Math.PI * total;
		
	}

	private static class Pancake implements Comparable<Pancake>
	{
		int r;
		int h;
		
		public Pancake(int r, int h)
		{
			this.r = r;
			this.h = h;
		}
		
		public long rH()
		{
			return ((long) r) * h;
		}
		
		public long r2()
		{
			return ((long) r) * r;
		}
		
		public long total()
		{
			return 2 * rH() + r2();
		}
		
		@Override
		public int compareTo(Pancake o)
		{
			return Long.compare(this.rH(), o.rH());
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
