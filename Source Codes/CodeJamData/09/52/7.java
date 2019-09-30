import java.io.*;
import java.util.*;

public class B implements Runnable
{	
	private String IFILE = "B-small-attempt0.in";
	private Scanner in;
	private PrintWriter out;
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		in.nextLine();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ":");
			String[] st = in.nextLine().split(" ");
			String str = st[0];
			int m = Integer.parseInt(st[1]);
			int n = in.nextInt();
			char[][] word = new char[n][];
			in.nextLine();
			for(int i = 0; i < n; i++)
				word[i] = in.nextLine().toCharArray();
			String[] p = str.split("\\+");
			int[] rr = new int[m + 1];
			for(int i = 0; i < p.length; i++)
			{
				char[] pp = p[i].toCharArray();
				int len = pp.length;
				int[][] mas = new int[n][len];
				for(int j = 0; j < len; j++)
					for(int k = 0; k < n; k++)
						for(int l = 0; l < word[k].length; l++)
							if (pp[j] == word[k][l])
								mas[k][j]++;
				if (m >= 1)
				{
					int res = 0;
					for(int i1 = 0; i1 < n; i1++)
					{
						int r = 1;
						for(int j = 0; j < len; j++)
							r *= mas[i1][j];
						res = (res + r) % 10009;
					}
					rr[1] += res;
				}
				if (m >= 2)
				{
					int res = 0;
					for(int i1 = 0; i1 < n; i1++)
						for(int i2 = 0; i2 < n; i2++)
						{
							int r = 1;
							for(int j = 0; j < len; j++)
								r *= mas[i1][j] + mas[i2][j];
							res = (res + r) % 10009;
						}
					rr[2] += res;
				}
				if (m >= 3)
				{
					int res = 0;
					for(int i1 = 0; i1 < n; i1++)
						for(int i2 = 0; i2 < n; i2++)
							for(int i3 = 0; i3 < n; i3++)
							{
								int r = 1;
								for(int j = 0; j < len; j++)
									r *= mas[i1][j] + mas[i2][j] + mas[i3][j];
								res = (res + r) % 10009;
							}
					rr[3] += res;
				}
				if (m >= 4)
				{
					int res = 0;
					for(int i1 = 0; i1 < n; i1++)
						for(int i2 = 0; i2 < n; i2++)
							for(int i3 = 0; i3 < n; i3++)
								for(int i4 = 0; i4 < n; i4++)
							{
								int r = 1;
								for(int j = 0; j < len; j++)
									r *= mas[i1][j] + mas[i2][j] + mas[i3][j] + mas[i4][j];
								res = (res + r) % 10009;
							}
					rr[4] += res;
				}
				if (m >= 5)
				{
					int res = 0;
					for(int i1 = 0; i1 < n; i1++)
						for(int i2 = 0; i2 < n; i2++)
							for(int i3 = 0; i3 < n; i3++)
								for(int i4 = 0; i4 < n; i4++)
									for(int i5 = 0; i5 < n; i5++)
							{
								int r = 1;
								for(int j = 0; j < len; j++)
									r *= mas[i1][j] + mas[i2][j] + mas[i3][j] + mas[i4][j] + mas[i5][j];
								res = (res + r) % 10009;
							}
					rr[5] += res;
				}
			}
			for(int i = 1; i <= m; i++)
				out.print(" " + rr[i] % 10009);
			out.println();
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
		new B().Run();
		//new Thread(new XXX()).start();
	}

}
