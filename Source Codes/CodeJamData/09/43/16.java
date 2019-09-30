import java.io.*;
import java.util.*;

public class C implements Runnable
{	
	private String IFILE = "C-large.in";
	private Scanner in;
	private PrintWriter out;
	
	int n;
	int m;
	boolean[][] mas;
	int[] q;
	int[] qq;
	boolean[] f;
	
	private boolean rec(int x)
	{
		for(int i = 0; i < n; i++)
			if (mas[x][i])
			{
				if (qq[i] == -1)
				{
					qq[i] = x;
					q[x] = i;
					return true;
				}
				else if (!f[i])
				{
					f[i] = true;
					if (rec(qq[i]))
					{
						qq[i] = x;
						q[x] = i;
						return true;
					}				
				}
			}
		return false;
	}
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			
			n = in.nextInt();
			m = in.nextInt();
			int[][] val = new int[n][m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					val[i][j] = in.nextInt();
			mas = new boolean[n][n];
			for(int i = 0; i < n; i++)
				Arrays.fill(mas[i], true);
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					for(int k = 0; k < m; k++)
						if (val[i][k] >= val[j][k])
							mas[i][j] = false;
			
			q = new int[n];
			Arrays.fill(q, -1);
			qq = new int[n];
			Arrays.fill(qq, -1);
			int res = n;
			for(int i = 0; i < n; i++)
				if (q[i] == -1)
				{
					f = new boolean[n];
					if (rec(i))
						res--;
				}
			out.println(res);
		}
		
		in.close();
		out.close();
	}
	
	public void run()
	{
		try		
		{
			Run();
		}
		catch(IOException e)
		{
			
		}
	}

	public static void main(String[] args) throws IOException
	{
		new C().Run();
		//new Thread(new XXX()).start();
	}

}
