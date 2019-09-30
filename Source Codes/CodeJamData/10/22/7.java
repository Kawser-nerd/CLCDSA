import java.io.*;
import java.util.*;

public class B implements Runnable
{	
	private String IFILE = "B-large.in";
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
			int m = in.nextInt();
			long len = in.nextInt();
			int t = in.nextInt();
			long[] pos = new long[n];
			int[] v = new int[n];
			for(int i = 0; i < n; i++)
				pos[i] = in.nextInt();
			for(int i = 0; i < n; i++)
				v[i] = in.nextInt();
			int res = 0;
			int sw = 0;
			for(int i = n - 1; i >= 0; i--)
			{
				if (m == 0)
					break;
				if (pos[i] + v[i] * t >= len)
				{
					res += sw;
					m--;
				}
				else
					sw++;
			}			
			if (m > 0)
				out.println("IMPOSSIBLE");
			else
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
		new B().Run();
		//new Thread(new XXX()).start();
	}

}
