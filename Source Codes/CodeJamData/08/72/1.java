import java.io.*;
import java.util.*;
public class Test1 {
	public static void main(String[] args)
	{
		P1 p=new P1();
		p.solve();
	}
}
class P1
{
	Scanner sc;
	public P1()
	{
		sc=new Scanner(System.in);
	}
	public void solve()
	{
		int n=sc.nextInt();
		for(int i=1;i<=n;i++)
		{
			System.out.printf("Case #%d: ",i);
			solve1();
		}
	}
	public void solve1()
	{
		int s=sc.nextInt();
		int[] bb=new int[s];
		for(int i=0;i<s;i++)
		{
			bb[i]=sc.nextInt();
		}
		int digit=11;
		boolean hasSolution=false;
		int solution=0;
		for(int i=0;i<1024;i++)
		{
			int[][] a=new int[s+1][14];
			int[] b=new int[s+1];
			int f=s+i;
			a[0][0]=10007-1;
			for(int j=0;j<=11;j++)
			{
				a[0][j+1]=(f>>j)%2;
			}
			a[0][13]=1;
			b[0]=0;
			for(int j=0;j<s;j++)
			{
				a[j+1][0]=0;
				for(int k=0;k<=11;k++)
				{
					a[j+1][k+1]=((j+i)>>k)%2;
				}
				a[j+1][13]=1;
				b[j+1]=bb[j];
			}
			if(i<0)
			{
				System.out.println(i);
				display(a,s+1,14);
			}
			Elimination eli=new Elimination(a,b,s+1,14);
			eli.solve();
			//System.out.println(i);
			if(eli.hasSolution())
			{
				if(!eli.canDetermine())
				{
					System.out.println("UNKNOWN");
					return;
				}
				int r=eli.get();
				//System.out.println("solution");
				//System.out.println(r);
				if(hasSolution)
				{
					if(solution!=r)
					{
						System.out.println("UNKNOWN");
						return;
					}
				}
				else
				{
					hasSolution=true;
					solution=r;
				}
			}
		}
		System.out.println(solution);
	}
	public static void display(int[][] a,int m,int n)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				System.out.printf("%d ",a[i][j]);
			}
			System.out.println();
		}
	}
}

class Elimination
{
	public int[][] a;//a[m][n]
	public int[] b;//b[m]
	int n;//number of unknowns;
	int m;//number of equations;
	int p=10007;
	static int[] inv;
	public static boolean initialized=false;
	int r;
	public Elimination(int[][] a,int[] b,int m,int n)
	{
		this.a=a;
		this.m=m;
		this.n=n;
		this.b=b;
		if(!initialized)
		{
			inv=new int[p];
			initialized=true;
			for(int i=1;i<p;i++)
			{
				for(int j=1;j<p;j++)
				{
					if((i*j)%p==1)
					{
						inv[i]=j;
					}
				}
			}
		}
	}
	public void swap(int s,int t)
	{
		for(int i=0;i<n;i++)
		{
			int v=a[s][i];
			a[s][i]=a[t][i];
			a[t][i]=v;
		}
		int u=b[s];
		b[s]=b[t];
		b[t]=u;
	}
	public void times(int s,int k)
	{
		for(int i=0;i<n;i++)
		{
			a[s][i]=(a[s][i]*k)%p;
		}
		b[s]=(b[s]*k)%p;
	}
	public void timesAdd(int s,int t,int k)
	{
		for(int i=0;i<n;i++)
		{
			a[t][i]=(a[t][i]+a[s][i]*k)%p;
		}
		b[t]=(b[t]+b[s]*k)%p;
	}
	public void solve()
	{
		r=0;
		for(int i=0;i<n;i++)
		{
			//System.out.print(i);
			for(int j=r;j<m;j++)
			{
				//System.out.print(" ");
				//System.out.println(j);
				if(a[j][i]!=0)
				{
					swap(j,r);
					times(r,inv[a[r][i]]);
					for(int k=0;k<m;k++)
					{
						if(k!=r)
						{
							timesAdd(r,k,p-(a[k][i]));
						}
					}
					r++;
					break;
				}
			}
			//System.out.println(r);
			//P1.display(a,m,n);
			try
			{
				//Thread.sleep(1000);
			}
			catch(Exception e)
			{

			}
		}
	}
	public boolean hasSolution()
	{
		for(int i=r;i<m;i++)
		{
			if(b[i]!=0)
			{
				return false;
			}

		}
		return true;
	}
	public boolean canDetermine()
	{
		if(a[0][0]==0)
		{
			return false;
		}
		for(int i=1;i<n;i++)
		{
			if(a[0][i]!=0)
			{
				return false;
			}
		}
		return true;
	}
	public int get()
	{
		return b[0];
	}
}

class P
{
	Scanner sc;
	public P()
	{
		sc=new Scanner(System.in);
	}
	public void solve()
	{
		int n=sc.nextInt();
		for(int i=1;i<=n;i++)
		{
			System.out.printf("Case #%d: ",i);
			solve1();
		}
	}
	public void solve1()
	{

	}
}
