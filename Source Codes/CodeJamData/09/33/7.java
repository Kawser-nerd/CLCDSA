import java.io.*;
import java.util.*;

public class C implements Runnable
{	
	private String IFILE = "C-large.in";
	private Scanner in;
	private PrintWriter out;
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			int n = in.nextInt();
			int m = in.nextInt() + 2;
			int[] mas = new int[m];
			mas[0] = 0;
			for(int i = 1; i < m - 1; i++)
				mas[i] = in.nextInt();
			mas[m - 1] = n + 1;
			int[][] d = new int[m][m];
			for(int i = 2; i < m; i++)
				for(int b = 0; b < m - i; b++)
				{
					int e = b + i;
					int min = Integer.MAX_VALUE;
					for(int j = b + 1; j < e; j++)
					{
						min = Math.min(min, d[b][j] + d[j][e] + mas[e] - mas[b] - 2);
					}
					d[b][e] = min;
				}
			out.println(d[0][m - 1]);
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
