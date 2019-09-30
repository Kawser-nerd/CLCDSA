import java.io.*;
import java.util.*;

public class C implements Runnable
{	
	private String IFILE = "C-large.in";
	private Scanner in;
	private PrintWriter out;
	
	private int MOD = 100003;
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			
			int n = in.nextInt();
			
			long[][] c = new long[n + 1][n + 1];
			c[0][0] = 1;
			for(int j = 1; j <= n; j++)
			{
				c[0][j] = 1;
				for(int i = 1; i <= n; i++)
					c[i][j] = (c[i - 1][j - 1] + c[i][j - 1]) % MOD;
			}
			
			long[][] mas = new long[n+1][n+1];
			for(int j = 2; j <= n; j++)
				mas[1][j] = 1;
			for(int i = 2; i <= n; i++)
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = 1; k < i; k++)
					{
						mas[i][j] = (mas[i][j] + mas[k][i] * c[j - i - 1][i - k - 1]) % MOD; 
					}
				}
			long result = 0;
			for(int i = 1; i <= n; i++)
				result = (result + mas[i][n]) % MOD;
			out.println(result);
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
