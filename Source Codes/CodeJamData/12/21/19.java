import java.io.*;
import java.util.*;

public class A implements Runnable
{	
	private String IFILE = "A-large.in"; 
	//private String IFILE = "input.txt";
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
			int[] mas = new int[n];
			for(int i = 0; i < n; i++)
				mas[i] = in.nextInt();
			int sum = 0;
			for(int i = 0; i < n; i++)
				sum += mas[i];
			double[] f = new double[n];
			for(int i = 0; i < n; i++)
				f[i] = (mas[i] + 0.0) / sum;
			for(int i = 0; i < n; i++)
			{
				double min = 0.0;
				double max = 1.0;
				while (max - min > 1e-14)
				{
					double v = (min + max) / 2.0;
					double cv = f[i] + v;
					double q = 0.0;
					for(int j = 0; j < n; j++)
						if (i != j)
							q += Math.max(cv - f[j], 0);
					if (q < 1.0 - v)
						min = v;
					else
						max = v;
				}
				out.print(" " + 100.0 * max);
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
		new A().Run();
		//new Thread(new XXX()).start();
	}

}
