import java.io.*;
import java.util.*;

public class TaskB implements Runnable
{	
	private String IFILE = "B-large.in";
	private Scanner in;
	private PrintWriter out;
	
	int n;
	int[] mas;
	Random rand;
	
	private int get(int a)
	{
		if (mas[a] != a)
			mas[a] = get(mas[a]);
		return mas[a];
	}
	
	private void union(int a, int b)
	{
		a = get(a);
		b = get(b);
		if (a != b)
		{
			if (rand.nextBoolean())
				mas[a] = b;
			else
				mas[b] = a;
		}
	}
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		rand = new Random(534);
		
		int MAXP = 1000010;
		boolean[] pr = new boolean[MAXP];
		Arrays.fill(pr, true);
		pr[0] = false;
		pr[1] = false;
		for(int i = 2; i < MAXP; i++)
			if (pr[i])
			{
				for(int j = 2 * i; j < MAXP; j += i)
					pr[j] = false;
			}
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			System.out.println(test);
			out.print("Case #" + test + ": ");
			
			long a = in.nextLong();
			long b = in.nextLong();
			long c = in.nextLong();
			n = (int)(b - a + 1);
			mas = new int[n];
			for(int i = 0; i < n; i++)
				mas[i] = i;
			for(long i = c; i < MAXP; i++)
			{
				int ii = (int)i;
				if (pr[ii])
				{
					long f = ((a - 1) / i + 1) * i;
					while (f + i <= b)
					{
						union((int)(f - a), (int)(f + i - a));
						f += i;
					}
				}
			}
			int res = 0;
			for(int i = 0; i < n; i++)
				if (mas[i] == i)
					res++;
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
		//new TaskB().Run();
		new Thread(new TaskB()).start();
	}

}
