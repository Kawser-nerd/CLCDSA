import java.io.*;
import java.util.*;

public class TaskC implements Runnable
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
			out.print("Case #" + test + ":");
			int n = in.nextInt();
			int m = in.nextInt();
			int[] mas = new int[m];
			for(int i = 0; i < m; i++)
			{
				int v = in.nextInt() - 1;
				int count = n;
				for(int j = 0; j < n; j++)
				{
					int pos = j % count;
					if (pos == v)
					{
						out.print(" " + (j + 1));
						break;
					}
					if (pos > v)
					{
						v += count - pos - 1;
					}
					else
					{
						v = v - pos - 1;
					}
					count--;
				}
				
			}
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
		new TaskC().Run();
		//new Thread(new XXX()).start();
	}

}
