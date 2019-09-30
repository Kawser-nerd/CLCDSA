import java.io.*;
import java.util.*;

public class A implements Runnable
{	
	private String IFILE = "A-large.in";
	//private String IFILE = "input.txt";
	private Scanner in;
	private PrintWriter out;
	
	private int nod(int x, int y)
	{
		if (x > y)
			return nod(y, x);
		while (x > 0)
		{
			int k = x;
			x = y % x;
			y = k;
		}
		return y;
	}
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			long n = in.nextLong();
			int pd = in.nextInt();
			int pg = in.nextInt();
			if (pg == 0 && pd != 0 || pg == 100 && pd != 100)
				out.println("Broken");
			else
			{
				int nod = nod(pd, 100);
				if (n >= 100 / nod)
					out.println("Possible");
				else
					out.println("Broken");
			}
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
