import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class B
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
		int ac = sc.nextInt();
		int aj = sc.nextInt();
		int tc = 720;
		int tj = 720;
		
		Activity[] a = new Activity[ac + aj];
		
		for (int i = 0; i < ac; i++)
		{
			a[i] = new Activity('c', sc.nextInt(), sc.nextInt());
			tc -= a[i].time(); 
		}
		
		for (int i = ac; i < ac + aj; i++)
		{
			a[i] = new Activity('j', sc.nextInt(), sc.nextInt());
			tj -= a[i].time(); 
		}
		
		Arrays.sort(a);
		
		ArrayList<Integer> ic = new ArrayList<Integer>();
		ArrayList<Integer> ij = new ArrayList<Integer>();
		ArrayList<Integer> im = new ArrayList<Integer>();
		
		for (int i = 0; i + 1 < ac + aj; i++)
		{
			int gap = a[i].gap(a[i + 1]);
			if (a[i].person == a[i + 1].person)
			{
				switch (a[i].person)
				{
					case 'c':
						ic.add(gap);
						break;
					default:
						ij.add(gap);
				}
			}
			else
			{
				im.add(gap);
			}
		}
		last:
		{
			int gap = a[ac + aj - 1].gap(a[0]) + 24 * 60;
			if (a[ac + aj - 1].person == a[0].person)
			{
				switch (a[ac + aj - 1].person)
				{
					case 'c':
						ic.add(gap);
						break;
					default:
						ij.add(gap);
				}
			}
			else
			{
				im.add(gap);
			}
		}
		
		Collections.sort(ic);
		Collections.sort(ij);
		Collections.sort(im);
		
		int switches = im.size();
		
		int sumC = 0;
		int sumJ = 0;
		int sumM = 0;
		
		for (int i = 0; i < ic.size(); i++)
		{
			sumC += ic.get(i);
		}
		for (int i = 0; i < ij.size(); i++)
		{
			sumJ += ij.get(i);
		}
		for (int i = 0; i < im.size(); i++)
		{
			sumM += im.get(i);
		}
		
		if (sumM + sumC >= tc && sumM + sumJ >= tj)
		{
			return switches;
		}
		
		if (sumM + sumC < tc)
		{
			tc -= sumM + sumC;
			int index = ij.size() - 1;
			while (tc > 0)
			{
				switches += 2;
				tc -= ij.get(index);
				index--;
			}
		}
		else
		{
			tj -= sumM + sumJ;
			int index = ic.size() - 1;
			while (tj > 0)
			{
				switches += 2;
				tj -= ic.get(index);
				index--;
			}
		}
		
		return switches;
	}
	
	private static class Activity implements Comparable<Activity>
	{
		char person;
		int start;
		int end;

		public Activity(char p, int s, int e)
		{
			person = p;
			start = s;
			end = e;
		}
		
		public int gap(Activity a)
		{
			return a.start - this.end;
		}

		public int time()
		{
			return end - start;
		}

		@Override
		public int compareTo(Activity o)
		{
			return this.start - o.start;
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
