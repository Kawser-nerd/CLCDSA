import java.io.*;
import java.util.*;

public class Main implements Runnable
{
	private final String IFILE = "B-large.in";
	//private final String IFILE = "";
	private final String OFILE = "output.txt";
	//private final String OFILE = "";

	private final int SIZE = 10010;

	private BufferedReader in;
	private PrintWriter out;

	public void run()
	{
		try
		{
			Run();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}

	int n, m;
	int[][] next;
	int result;

	private void test(int[] mas)
	{
		int p = 1;
		int count = 0;
		while (p <= 10000)
		{
			int max = 0;
			for(int k : mas)
				max = Math.max(max, next[k][p]);
			if (max == 0)
				return;
			p = max;
			count++;
		}
		result = Math.min(result, count);
	}

	public void Run() throws IOException
	{
		in = new BufferedReader(new FileReader(new File(IFILE)));
		out = new PrintWriter(OFILE);
		int dd = Integer.parseInt(in.readLine());
		for(int d = 1; d <= dd; d++)
		{
			out.print("Case #" + d + ": ");
			n = Integer.parseInt(in.readLine());
			m = 0;
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			int[] col = new int[n];
			int[] b = new int[n];
			int[] e = new int[n];
			for(int i = 0; i < n; i++)
			{
				StringTokenizer st = new StringTokenizer(in.readLine());
				String name = st.nextToken();
				if (!map.containsKey(name))
					map.put(name, m++);
				col[i] = map.get(name);
				b[i] = Integer.parseInt(st.nextToken());
				e[i] = Integer.parseInt(st.nextToken());
			}

			next = new int[m][SIZE];
			for(int i = 0; i < n; i++)
			{
				int c = col[i];
				int ee = e[i];
				for(int j = b[i]; j <= ee; j++)
					next[c][j] = Math.max(next[c][j], ee + 1);
			}

			result = Integer.MAX_VALUE;
			for(int i = 0; i < m; i++)
			{
				test(new int[] {i});
				for(int j = i + 1; j < m; j++)
				{
					test(new int[] {i, j});
					for(int k = j + 1; k < m; k++)
					{
						test(new int[] {i, j, k});
					}
				}
			}

			System.out.println(d);
			if (result == Integer.MAX_VALUE)
				out.println("IMPOSSIBLE");
			else
				out.println(result);
		}
		in.close();
		out.close();
	}

	public static void main(String[] args) throws IOException
	{
		new Main().Run();
		//new Thread(new Main()).start();
	}

}
