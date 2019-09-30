import java.io.*;
import java.util.*;

public class A implements Runnable
{	
	private String IFILE = "A-large.in";
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
			in.nextLine();
			int[] mas = new int[n];
			for(int i = 0; i < n; i++)
			{
				char[] c = in.nextLine().toCharArray();
				for(int j = 0; j < n; j++)
					if (c[j] == '1')
						mas[i] = j;
			}
			
			int res = 0;
			for(int i = 0; i < n; i++)
			{
				int pos = 0;
				for(int j = i; j < n; j++)
					if (mas[j] <= i)
					{
						pos = j;
						break;
					}
				res += pos - i;
				for(int j = pos; j > i; j--)
					mas[j] = mas[j - 1];
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
		new A().Run();
		//new Thread(new XXX()).start();
	}

}
