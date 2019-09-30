import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args)
	{
		P32 p=new P32();
		p.solve();
	}
}
class P32
{
	static Scanner sc=new Scanner(System.in);
	int r;
	int c;
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
	ArrayList<Integer> getList(int n)
	{
		ArrayList<Integer> list=new ArrayList<Integer>();
		if(n==2)
		{
			list.add(0);
			return list;
		}
		if(n==3)
		{
			list.add(1);
			return list;
		}
		if(n%3==2)
		{
			for(int i=0;i<n;i+=3)
			{
				list.add(i);
			}
			return list;
		}
		if(n%3==0)
		{
			for(int i=1;i<n;i+=3)
			{
				list.add(i);
			}
			return list;
		}
		throw new RuntimeException();
	}
	int total()
	{
		ArrayList<Integer> rows=new ArrayList<Integer>();
		ArrayList<Integer> columns=new ArrayList<Integer>();
		if(r%3==1)
		{
			rows=getList(r+1);
		}
		else
		{
			rows=getList(r);
		}
		if(c%3==1)
		{
			columns=getList(c+1);
		}
		else
		{
			columns=getList(c);
		}
		int t=0;
		for(int i:rows)
		{
			for(int j:columns)
			{
				t+=puzzle[i][j];
			}
		}
		return t;
	}
	int solution()
	{
		int tt=total();
		ArrayList<Integer> rows=new ArrayList<Integer>();
		ArrayList<Integer> columns=new ArrayList<Integer>();
		if(c%3==1)
		{
			columns=getList(c+1);
		}
		else
		{
			columns=getList(c);
		}
		int middle=(r-1)/2;
		if(r%6==1)
		{
			for(int i=1;i<middle-1;i+=3)
			{
				rows.add(i);
			}
			for(int i=r-2;i>middle+1;i-=3)
			{
				rows.add(i);
			}
		}
		else if(r%6==3)
		{
			for(int i=0;i<middle;i+=3)
			{
				rows.add(i);
			}
			for(int i=r-1;i>middle;i-=3)
			{
				rows.add(i);
			}
		}
		else if(r%6==5)
		{
			for(int i=0;i<middle-1;i+=3)
			{
				rows.add(i);
			}
			for(int i=r-1;i>middle+1;i-=3)
			{
				rows.add(i);
			}
		}
		int t=0;
		for(int i:rows)
		{
			for(int j:columns)
			{
				t+=puzzle[i][j];
			}
		}
		if(r%6==1)
		{
			return tt-t;
		}
		if(r%6==3)
		{
			return t-tt;
		}
		if(r%6==5)
		{
			return tt-t;
		}
		throw new RuntimeException();
	}
	void read()
	{
		r=sc.nextInt();
		c=sc.nextInt();
		puzzle=new int[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				puzzle[i][j]=sc.nextInt();
			}
		}
	}
	void solve1()
	{
		read();
		int s=solution();
		System.out.println(s);
	}
}
class P5
{
	static Scanner sc=new Scanner(System.in);
	int[][] state;//0=.,1=?,2=#
	int n;
	int m;
	public void read()
	{
		n=sc.nextInt();
		m=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			String s=sc.nextLine();
			for(int j=0;j<m;j++)
			{
				char c=s.charAt(j);
				if(c=='.')
				{
					state[i][j]=0;
				}
				if(c=='#')
				{
					state[i][j]=2;
				}
				if(c=='?')
				{
					state[i][j]=1;
				}
			}
		}
	}
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
		read();

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