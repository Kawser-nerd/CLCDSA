import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable
{
	static Scanner scanner;
	static BufferedReader input;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception
	{
		new Thread(new Main()).start();
	}

	public void run()
	{
		try
		{
			input = new BufferedReader(new FileReader("input.txt"));
			scanner = new Scanner(input);
			pw = new PrintWriter(new File("output.txt"));

			solve();

			pw.close();
		}
		catch(Exception e)
		{
			pw.close();
			e.printStackTrace();
			System.exit(1);
		}
	}

	public void solve() throws Exception
	{
		int qq, n, t;
		BigInteger[][] d = new BigInteger[51][51];
		int[][] a = new int[51][10240];
		BigInteger[][] s = new BigInteger[51][10240];
		BigInteger[][] bs = new BigInteger[51][10240];

		qq = scanner.nextInt();
		for(int ii = 0; ii < qq; ii++)
		{
			n = scanner.nextInt();
			t = scanner.nextInt();
			int m = 10;
			for(int i = 0; i < t; i++)
			{
				Arrays.fill(a[i], 0);
				int l;
				l = scanner.nextInt();
				l--;
				a[i][0] = 1;
				for(int j = 0; j < l; j++)
				{
					int x;
					x = scanner.nextInt();
					if (x > m) m = x;
					a[i][x-1] = 1;
				}
			}
			BigInteger bn = BigInteger.valueOf(n);
			for(int i = 0; i < t; i++)
			{
				s[i][0] = BigInteger.valueOf(a[i][0]);
				bs[i][0] = bn.subtract(s[i][0]);
				for(int j = 1; j <= m+1; j++)
				{
					s[i][j] = s[i][j-1].add(BigInteger.valueOf(a[i][j]));
					bs[i][j] = bn.subtract(s[i][j]);
				}
			}
			BigInteger ans = BigInteger.ZERO;
			int nn = n;
			if (nn > m)
			{
				nn = m;
			}
			for(int i = 0; i < m+1; i++)
			{
				d[0][0] = BigInteger.ONE;
				for(int j = 1; j <= t; j++)
				{
					d[0][j] = BigInteger.ZERO;
				}
				for(int k = 0; k < t; k++)
				{
					for(int j = 0; j <= k+1; j++)
					{
						if (j == k+1) d[k+1][j] = BigInteger.ZERO;
						else d[k+1][j] = d[k][j].multiply(bs[k][i]);
						if (j > 0) d[k+1][j] = d[k+1][j].add(d[k][j-1].multiply(s[k][i]));
					}
				}

				if (i < nn)
				{
					for(int j = 1; j <= t; j++)
					{
						ans = ans.add(d[t][j].multiply(BigInteger.valueOf(j).multiply(BigInteger.valueOf(j))));
					}
				}
				if (i % 100 == 0) System.out.println(i);
			}
	    
/*			for(int i = 0; i < nn; i++)
			{
				for(int j = 1; j <= t; j++)
				{
					ans = ans.add(d[t % 2][i][j].multiply(BigInteger.valueOf(j).multiply(BigInteger.valueOf(j))));
				}
			}*/
			if (n > nn)
			{
				for(int j = 1; j <= t; j++)
				{
					ans = ans.add(d[t][j].multiply(BigInteger.valueOf(j).multiply(BigInteger.valueOf(j).multiply(bn.subtract(BigInteger.valueOf(nn))))));
				}
			}
			
			BigInteger p, q, r;
			p = ans;
			q = BigInteger.ONE;
			for(int i = 0; i < t; i++)
			{
				q = q.multiply(bn);
			}
			r = p.gcd(q);
			p = p.divide(r);
			q = q.divide(r);
			pw.println("Case #" + (ii+1) + ": " + p.divide(q) + "+" + p.mod(q) + "/" + q);
		}
		
	}
}
