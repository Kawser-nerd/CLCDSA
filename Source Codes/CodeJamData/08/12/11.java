import java.io.*;
import java.util.*;
import java.math.*;

public class B
{
	public static void main(String[] args) throws Throwable
	{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader("A-small.in")));
		// BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		in.nextToken();
		int t = (int)in.nval, iter = 0;
		while(t-->0)
		{
			iter++;
			in.nextToken();
			int N = (int)in.nval;
			in.nextToken();
			int M = (int)in.nval;
			boolean[][] cust = new boolean[M][4000];
			for(int i = 0; i < M; i++)
			{
				in.nextToken();
				int num = (int)in.nval;
				for(int j = 0; j < num; j++)
				{
					in.nextToken();
					int a = ((int)in.nval-1);
					in.nextToken();
					int b = (int)in.nval;
					b *= 2000;
					cust[i][a+b] = true;
				}
			}
			int bestRR = -1, bestVal = 1000000, sent = 1<<20;
			boolean[] paw = new boolean[4000];
			for(int i = 0; i < 2000; i++)
				paw[i] = true;
			boolean chg = true;
			while(chg)
			{
				chg = false;
				for(int i = 0; i < M; i++)
				{
					boolean f = false;
					for(int k = 0; k < 4000; k++)
						f |= paw[k]&&cust[i][k];
					if(!f)
					{
						for(int k = 2000; k < 4000; k++)
							if(cust[i][k])
							{
								chg = true;
								paw[k-2000] = false;
								paw[k] = true;
							}
					}
				}
			}
			boolean corr = true;
			for(int i = 0; i < M; i++)
			{
				boolean yup = false;
				for(int j = 0; j < 4000; j++)
					if(cust[i][j] && paw[j])
						yup = true;
				if(!yup)
					corr = false;
			}
			if(!corr)
				out.println("Case #"+iter+": IMPOSSIBLE");
			else
			{
				out.print("Case #"+iter+": ");
				for(int i = 2000; i < 2000+N; i++)
					if(paw[i])
						out.print("1 ");
					else
						out.print("0 ");
				out.println();
			}
		}
		out.close();
		System.exit(0);
	}
}