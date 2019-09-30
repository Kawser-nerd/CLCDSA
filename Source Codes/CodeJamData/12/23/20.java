import java.io.*;
import java.util.*;

public class C implements Runnable
{
	
	private final int MAX_VALUE = 100000 * 20 + 10;
	 
	private String IFILE = "C-small-attempt0.in";
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
			out.println("Case #" + test + ":");
			int n = in.nextInt();
			int[] mas = new int[n];
			for(int i = 0; i < n; i++)
				mas[i] = in.nextInt();
			Arrays.sort(mas);
			int[] f = new int[MAX_VALUE];
			Arrays.fill(f, -1);
			f[0] = 0;
			boolean ok = false;
			for(int i = 0; i < n; i++)
			{
				for(int d = MAX_VALUE - 1; d >= 0; d--)
				{
					if (f[d] == -1)
						continue;
					
					int dd = d + mas[i];
					if (f[dd] != -1)
					{
						ok = true;
						int z = dd;
						while (z != 0)
						{
							if (z != dd)
								out.print(" ");
							out.print(mas[f[z]]);
							z -= mas[f[z]];
						}
						out.println();
						
						out.print(mas[i]);
						z = d;
						while (z != 0)
						{
							out.print(" " + mas[f[z]]);
							z -= mas[f[z]];
						}
						out.println();
						break;
					}
					else
						f[dd] = i;
				}
				if (ok)
					break;
			}
			if (!ok)
				out.println("Impossible");
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
