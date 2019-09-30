import java.io.*;
import java.util.*;
import library.*;
class Main
{
	public static void main(String[] args) throws IOException
	{
		P2 p=new P2();
		p.solve();
	}
}
class P1
{
	static Input in=new Input();
	static PrintStream out;
	void solve1() throws IOException
	{
		int n=in.readInt();
		int[] a=new int[n];
		int[] b=new int[n];
		for(int i=0;i<n;i++)
		{
			a[i]=in.readInt();
		}
		for(int i=0;i<n;i++)
		{
			b[i]=in.readInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		long t=0;
		for(int i=0;i<n;i++)
		{
			long s=a[i];
			long r=b[n-1-i];
			t+=(s*r);
		}
		out.println(t);
	}
	public void solve() throws IOException
	{
		out=System.out;
		int n=in.readInt();
		for(int i=0;i<n;i++)
		{
			out.printf("Case #%d: ", i+1);
			solve1();
		}
		out.close();
	}
}
class P2
{
	static Input in=new Input();
	static PrintStream out;
	void solve1() throws IOException
	{
		int n=in.readInt();
		int[] c=new int[n];
		for(int i=0;i<n;i++)
		{
			c[i]=0;
		}
		int m=in.readInt();
		int[] malted=new int[m];
		Vector<HashSet<Integer>> unmalted=new Vector<HashSet<Integer>>();
		unmalted.setSize(m);
		for(int i=0;i<m;i++)
		{
			malted[i]=-1;
			unmalted.set(i, new HashSet<Integer>());
			int p=in.readInt();
			for(int j=0;j<p;j++)
			{
				int s=in.readInt()-1;
				int t=in.readInt();
				if(t==0)
				{
					unmalted.get(i).add(s);
				}
				else
				{
					malted[i]=s;
				}
			}
		}
		HashSet<Integer> unsatisfied=new HashSet<Integer>();
		for(int i=0;i<m;i++)
		{
			unsatisfied.add(i);
		}
		while(true)
		{
			LinkedList<Integer> l=new LinkedList<Integer>();
			if(unsatisfied.size()==0)
			{
				break;
			}
			for(int i:unsatisfied)
			{
				if(unmalted.get(i).size()==0)
				{
					l.addLast(i);
				}
			}
			if(l.size()==0)
			{
				break;
			}
			for(int i:l)
			{
				if(malted[i]==-1)
				{
					out.println(" IMPOSSIBLE");
					return;
				}
				int f=malted[i];
				c[f]=1;
				for(int j=0;j<m;j++)
				{
					if(unsatisfied.contains(j))
					{
						if(malted[j]==f)
						{
							unsatisfied.remove(j);
						}
					}
				}
				for(int j:unsatisfied)
				{
					if(unmalted.get(j).contains(f))
					{
						unmalted.get(j).remove(f);
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			out.printf(" %d", c[i]);
		}
		out.println();
	}
	public void solve() throws IOException
	{
		out=System.out;
		int n=in.readInt();
		for(int i=0;i<n;i++)
		{
			out.printf("Case #%d:", i+1);
			solve1();
		}
		out.close();
	}
}
class P3
{
	static Input in=new Input();
	static PrintStream out;
	int[][] mult(int[][] a,int[][] b)
	{
		int[][] c=new int[2][2];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				c[i][j]=0;
				for(int k=0;k<2;k++)
				{
					c[i][j]+=(a[i][k]*b[k][j]);
					c[i][j]=(c[i][j]+1000)%1000;
				}
				//System.out.println(c[i][j]);
			}
		}
		return c;
	}
	int[][] pow(int[][] a,int n)
	{
		if(n==1)
		{
			return a;
		}
		if(n%2==0)
		{
			return pow(mult(a,a),n/2);
		}
		else
		{
			return mult(pow(mult(a,a),n/2),a);
		}
	}
	void solve1() throws IOException
	{
		int[][] a=new int[2][2];
		a[0][0]=6;
		a[0][1]=-4;
		a[1][0]=1;
		a[1][1]=0;
		int n=in.readInt();
		int[][] b=pow(a,n);
		int s=6*b[1][0]+2*b[1][1];
		s=(s+1999)%1000;
		int a0=s%10;
		int a1=(s/10)%10;
		int a2=(s/100)%10;
		out.printf("%d%d%d\n", a2,a1,a0);
	}
	public void solve() throws IOException
	{
		out=System.out;
		int n=in.readInt();
		for(int i=0;i<n;i++)
		{
			out.printf("Case #%d: ", i+1);
			solve1();
		}
		out.close();
	}
}