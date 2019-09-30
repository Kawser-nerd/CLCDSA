import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class A implements Runnable
{
	public static String file = "A-large";
	public BufferedReader in;
	public BufferedWriter out;
	int[] a;
	int[] b;
	int[] c;
	int n;
	int max;
	int[][] tree;
	public void clear()
	{
		int s=10001;
		for (int i=0;i<15;i++)
		{
			Arrays.fill(tree[i], 0,s-1,0);
			s=(s+1)/2;
		}
	}
	
	public void addTree(int level, int cell, int left,int right)
	{
		int start=cell<<level;
		int end=(cell+1)<<level;
		if (left==start && right==end)
		{
			tree[level][cell]++;
			return;
		}
		if (level==0)
		{
			System.out.println("bug");
		}
		int middle=(2*cell+1)<<(level-1);
		if (left<middle)
		{
			addTree(level-1,2*cell,left,Math.min(right, middle));
		}
		if (middle<right)
		{
			addTree(level-1,2*cell+1,Math.max(left,middle),right);
		}
	}
	
	public void reduce()
	{
		for (int level=14;level>0;level--)
		{
			for (int i=0;(i<<level)<=10000;i++)
			{
				tree[level-1][2*i]+=tree[level][i];
				tree[level-1][2*i+1]+=tree[level][i];
			}
		}
		for (int i=0;i<=10000;i++)
		{
			max=Math.max(max,tree[0][i]);
		}
	}
	
	public void solve1()
	{
		tree=new int[15][20001];
		for (int level=0;level<=10000;level++)
		{
			clear();
			for (int i=0;i<n;i++)
			{
				if (level<a[i])
				{
					continue;
				}
				int left=b[i];
				int right=c[i]-level;
				if (left<=right)
				{
					addTree(14,0,left,right+1);
				}
			}
			reduce();
		}
	}

	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			n=Integer.parseInt(readWord());
			a=new int[n];
			b=new int[n];
			c=new int[n];
			for (int i=0;i<n;i++)
			{
				a[i]=Integer.parseInt(readWord());
				b[i]=Integer.parseInt(readWord());
				c[i]=Integer.parseInt(readWord());
				c[i]=10000-c[i];
			}
			max=0;
			solve1();
			out.write("Case #" + test + ": " + max+ "\n");
		}
	}

	public String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = in.read();
			if (c < 0)
			{
				return "";
			}
			if (c > 32)
			{
				break;
			}
		}
		while (true)
		{
			b.append((char) c);
			c = in.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	public void run()
	{
		try
		{
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new BufferedWriter(new FileWriter(file + ".out"));
			solve();
			in.close();
			out.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		try
		{
			new Thread(new A()).start();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

}
