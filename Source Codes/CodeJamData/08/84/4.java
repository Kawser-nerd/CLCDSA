import java.io.*;
import java.util.*;

public class Main implements Runnable
{
	private final String IFILE = "D-large.in";
	//private final String IFILE = "";
	private final String OFILE = "output.txt";
	//private final String OFILE = "";

	private int MOD = 30031;

	private Scanner in;
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

	int num;

	public long[][] mult(long[][] a1, long[][] a2)
	{
		long[][] result = new long[num][num];
		for(int i = 0; i < num; i++)
			for(int j = 0; j < num; j++)
			{
				long sum = 0;
				for(int k = 0; k < num; k++)
					sum += a1[i][k] * a2[k][j];
				result[i][j] = sum % MOD;
			}
		return result;
	}

	private long[][] st(long[][] a, int s)
	{
		if (s == 1)
			return a;
		if ((s & 1) == 0)
			return st(mult(a, a), s / 2);
		else
			return mult(st(a, s - 1), a);
	}

	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter(OFILE);
		int dd = in.nextInt();
		for(int d = 1; d <= dd; d++)
		{
			out.print("Case #" + d + ": ");
			int n = in.nextInt();
			int m = in.nextInt();
			int p = in.nextInt();
			HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
			num = 0;
			int pp = 1 << p;
			int[] arr = new int[pp];
			for(int i = 0; i < pp; i++)
				if (Integer.bitCount(i) == m)
				{
					arr[num] = i;
					map.put(i, num++);
				}

			long[][] mas = new long[num][num];
			for(int i = 0; i < num; i++)
			{
				int x = arr[i];
				//	mas[i][map.get(x >> 1)] ++;
				if ((x & 1) == 1)
				{
					int xx = x >> 1;
					for(int k = 0; k < p; k++)
					{
						if (((xx >> k) & 1) == 0)
							mas[i][map.get(xx + (1 << k))] ++;
					}
				}
			}

			long[][] res = st(mas, n - m);
			out.println(res[0][0]);
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
