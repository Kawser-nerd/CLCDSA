import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args)
	{
		P1 p=new P1();
		p.solve();
	}
}
class P2
{
	static Scanner sc=new Scanner(System.in);
	public void solve()
	{
		int n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.printf("Case #%d: ",i+1);
			solve1();
		}
	}
	void solve1()
	{

	}
}
class P3
{
	static Scanner sc=new Scanner(System.in);
	int[][] puzzle;
	public void solve()
	{
		int n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.printf("Case #%d: ",i+1);
			solve1();
		}
	}
	void solve1()
	{
		int r=sc.nextInt();
		int c=sc.nextInt();
		puzzle=new int[r][c];
		int max=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				puzzle[i][j]=sc.nextInt();
			}
		}
		loop:
		for(int k=0;k<(1<<(r*c));k++)
		{
			int[][] b=new int[r][c];
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					b[i][j]=0;
				}
			}
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if((k>>(i*c+j))%2==1)
					{
						for(int di=-1;di<=1;di++)
						{
							for(int dj=-1;dj<=1;dj++)
							{
								int ni=i+di;
								int nj=j+dj;
								if(0<=ni && ni<r && 0<=nj && nj<c)
								{
									b[ni][nj]++;
									if(b[ni][nj]>puzzle[ni][nj])
									{
										continue loop;
									}
								}
							}
						}
					}
				}
			}
			boolean flag=true;
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(puzzle[i][j]!=b[i][j])
					{
						flag=false;
					}
				}
			}
			if(flag)
			{
				//System.out.println("sadgfsdl");
				//System.out.println(k);
				int middle=(r-1)/2;
				int t=0;
				for(int j=0;j<c;j++)
				{
					if((k>>(middle*c+j))%2==1)
					{
						t++;
					}
				}
				if(t>max)
				{
					max=t;
					//System.out.println(k);
				}
			}
		}
		System.out.println(max);
	}
}
class P1
{
	static Scanner sc=new Scanner(System.in);
	public void solve()
	{
		int n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.printf("Case #%d: ",i+1);
			solve1();
		}
	}
	void solve1()
	{
		int n=sc.nextInt();
		int[] a=new int[n];
		int[] b=new int[n];
		int[] c=new int[n];
		int max=0;
		for(int i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
			c[i]=sc.nextInt();
		}
		for(int ia=0;ia<=10000;ia++)
		{
			for(int ib=0;ib<=10000-ia;ib++)
			{
				int ic=10000-ia-ib;
				int t=0;
				for(int i=0;i<n;i++)
				{
					if(ia>=a[i] && ib>=b[i] && ic>=c[i])
					{
						t++;
					}
				}
				if(t>max)
				{
					max=t;
				}
			}
		}
		System.out.println(max);
	}
}
class P
{
	static Scanner sc=new Scanner(System.in);
	public void solve()
	{
		int n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.printf("Case #%d: ",i+1);
			solve1();
		}
	}
	void solve1()
	{
		System.out.println();
	}
}