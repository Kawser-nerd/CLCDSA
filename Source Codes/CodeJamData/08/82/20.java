import java.io.*;
import java.util.*;

public class Main implements Runnable{

	int oo = Integer.MAX_VALUE;
	Scanner in;
	PrintWriter out;

	HashMap<String, Integer> mapCol;
	int ret = oo, n;
	int [] le, ri;
	String [] col;
	int [] was = new int[10001];

	void rec(int i, int mask)
	{
		if(i == n)
		{

			/*if(mask == 5)
				System.out.print("");
			int [] c = new int[2 * n];
			int [] t = new int[2 * n];
			int nn = 0;
			for(int j=0;j<n;j++)
			{
				if((mask & (1 << j)) == 0)continue;
				c[nn] = le[j];
				t[nn++] = 0;
				c[nn] = ri[j];
				t[nn++] = 1;
			}
			for(int j=0;j<nn;j++)
				for(int k=j+1;k<nn;k++)
					if(c[j] > c[k] || (c[j] == c[k] && t[j] < t[k]))
					{
						int tt = c[j];c[j] = c[k];c[k] = tt;
						tt = t[j];t[j] = t[k];t[k] = tt;
					}
			int co = 0;
			int j = 0;
			int min = oo, max = -oo;

			while(j < nn)
			{
				int cur = c[j];
				if(cur < min)
					min = cur;
				if(cur > max)
					max = cur;
				while(j < nn && c[j] == cur && t[j] == 1)
				{
					j++;
					co--;
				}
				while(j < nn && c[j] == cur && t[j] == 0)
				{
					j++;
					co++;
				}

				if(co == 0 && j < nn && c[j] != cur + 1)
					return;
			}*/

			Arrays.fill(was, -1);
			for(int j=0;j<n;j++)
				if((mask & (1 << j)) > 0)
				{
					int c = mapCol.get(col[j]);
					for(int k=le[j];k<=ri[j];k++)
						was[k] = c;
				}
			int maskC = 0;
			for(int j=1;j<=10000;j++)
				if(was[j] == -1)
					return;
				else
					maskC |= (1 << was[j]);



			//if(min == 1 && max == 10000)
			if(Integer.bitCount(maskC) <= 3)
				if(Integer.bitCount(mask) < ret)
				{
					ret = Integer.bitCount(mask);
				}
			return;
		}

		rec(i + 1, mask);

		//int c = mapCol.get(col[i]);
		//int nmask = mask | (1 << c);
		//if(Integer.bitCount(nmask) <= 3)
		//{
		rec(i + 1, mask | (1 << i));
		//}
	}

	public void Run()throws IOException
	{
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter("output.txt");

		int nt = in.nextInt();
		in.nextLine();
		for(int it=0;it<nt;it++)
		{
			n = in.nextInt();
			in.nextLine();
			out.print("Case #" + (it + 1) + ": ");
			mapCol = new HashMap<String, Integer>();
			int nc = 0;
			ret = oo;
			col = new String[n];
			le = new int[n];
			ri = new int[n];
			for(int i=0;i<n;i++)
			{
				StringTokenizer st = new StringTokenizer(in.nextLine());
				col[i] = st.nextToken();
				if(!mapCol.containsKey(col[i]))
				{
					mapCol.put(col[i], nc);
					nc++;
				}

				le[i] = Integer.parseInt(st.nextToken());
				ri[i] = Integer.parseInt(st.nextToken());
			}

			rec(0, 0);
			if(ret == oo)
				out.println("IMPOSSIBLE");
			else
				out.println(ret);

		}

		in.close();
		out.close();
	}

	public void run() {
		try
		{
			Run();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws IOException
	{
		new Main().Run();
		//new Thread(new Main()).start();
	}

}
