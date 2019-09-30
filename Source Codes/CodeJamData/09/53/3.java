import java.io.*;
import java.util.*;

public class C implements Runnable
{	
	//private String IFILE = "input.txt";
	private String IFILE = "C-large.in";
	private Scanner in;
	private PrintWriter out;
	
	private class Pset implements Comparable<Pset>
	{
		int x;
		int y;
		
		public Pset(int x, int y)
		{
			this.x = x;
			this.y = y;
		}

		public int compareTo(Pset o)
		{
			return o.x - x;
		}
		
		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
		
	}
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			int n = in.nextInt();
			Pset[] mas = new Pset[n];
			for(int i = 0; i < n; i++)
				mas[i] = new Pset(in.nextInt(), in.nextInt());
			Arrays.sort(mas);
			int[] pru = new int[n];
			int[] pr = new int[n];
			int[] prd = new int[n];
			Arrays.fill(pru, -1);
			Arrays.fill(pr, -1);
			Arrays.fill(prd, -1);
			int result = 1;
			for(int i = 0; i < n; i++)
			{
				for(int j = i - 1; j >= 0; j--)
					if (mas[i].y - 1 == mas[j].y)
					{
						pru[i] = j;
						result = 2;
						break;
					}
				for(int j = i - 1; j >= 0; j--)
					if (mas[i].y == mas[j].y)
					{
						pr[i] = j;
						result = 2;
						break;
					}
				for(int j = i - 1; j >= 0; j--)
					if (mas[i].y + 1== mas[j].y)
					{
						prd[i] = j;
						result = 2;
						break;
					}
			}
			
			for(int i = 0; i < n; i++)
				if (pr[i] >= 0)
				{
					int f1 = i;
					int f2 = pr[f1];
					if (pru[f1] >= 0 && pru[f2] >= 0 && pru[f1] == pru[f2] ||
						prd[f1] >= 0 && prd[f2] >= 0 && prd[f1] == prd[f2] || 
						pru[f1] >= 0 && prd[pru[f1]] == f2 ||
						prd[f1] >= 0 && pru[prd[f1]] == f2)
					{
						result = 3;
						break;
					}
				}				
				
			for(int i = 0; i < n; i++)
				if (pr[i] >= 0 && pr[pr[i]] >= 0)
				{
					int f1 = i;
					int f2 = pr[f1];
					int f3 = pr[f2];
					if (pru[f1] == -1 || prd[f1] == -1)
						continue;
					if (pru[f2] == -1 || prd[f2] == -1)
						continue;
					int count = 0;
					int u = pru[f1];
					while (u != pru[f2])
					{
						u = pr[u];
						count++;
					}
					int d = prd[f1];
					while (d != prd[f2])
					{
						d = pr[d];
						count++;
					}
					if (count % 2 == 1)
					{
						result = 4;
						break;
					}					
				}
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
