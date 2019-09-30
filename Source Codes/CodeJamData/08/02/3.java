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
class P2
{
	static Input in=new Input();
	static PrintStream out;
	int readTime(String s)
	{
		int hh=Integer.parseInt(s.substring(0,2));
		int mm=Integer.parseInt(s.substring(3,5));
		return hh*60+mm;
	}
	public void solve1() throws IOException
	{
		int t=in.readInt();
		int na=in.readInt();
		int nb=in.readInt();
		int[] da=new int[na];
		int[] aa=new int[na];
		int[] db=new int[nb];
		int[] ab=new int[nb];
		for(int i=0;i<na;i++)
		{
			da[i]=readTime(in.readString());
			aa[i]=readTime(in.readString());
		}
		for(int i=0;i<nb;i++)
		{
			db[i]=readTime(in.readString());
			ab[i]=readTime(in.readString());
		}
		int ra=solve2(t,na,nb,da,ab);
		int rb=solve2(t,nb,na,db,aa);
		out.printf("%d %d\n", ra,rb);
	}
	int solve2(int t,int na,int nb,int[] da,int[] ab)
	{
		int[] x=new int[1440];
		for(int i=0;i<1440;i++)
		{
			x[i]=0;
		}
		for(int i=0;i<na;i++)
		{
			for(int j=da[i];j<1440;j++)
			{
				x[j]--;
			}
		}
		for(int i=0;i<nb;i++)
		{
			for(int j=ab[i]+t;j<1440;j++)
			{
				x[j]++;
			}
		}
		int min=0;
		for(int i=0;i<1440;i++)
		{
			if(min>x[i])
			{
				min=x[i];
			}
		}
		return -min;
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

/*
class P1
{
	static Input in=new Input();
	static PrintStream out;
	public void solve1() throws IOException
	{
		int inf=10000;
		int n=in.readInt();
		String[] engines=new String[n];
		for(int i=0;i<n;i++)
		{
			engines[i]=in.readLine();
			//out.println(engines[i]);
		}
		Translation<String> trans=new Translation<String>();
		for(int i=0;i<n;i++)
		{
			trans.add(engines[i]);
		}
		int m=in.readInt();
		if(m==0)
		{
			out.printf("0\n");
			return;
		}
		int[] search=new int[m];
		for(int i=0;i<m;i++)
		{
			search[i]=trans.get(in.readLine());
		}
		int[][] dp=new int[m][n];
		for(int i=0;i<n;i++)
		{
			dp[0][i]=0;
		}
		if(search[0]!=-1)
		{
			dp[0][search[0]]=inf;
		}
		for(int i=1;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(search[i]==j)
				{
					dp[i][j]=inf;
				}
				else
				{
					int min=dp[i-1][j];
					for(int k=0;k<n;k++)
					{
						if(min>dp[i-1][k]+1)
						{
							min=dp[i-1][k]+1;
						}
					}
					dp[i][j]=min;
				}
			}
		}
		int min2=inf;
		for(int i=0;i<n;i++)
		{
			if(min2>dp[m-1][i])
			{
				min2=dp[m-1][i];
			}
		}
		out.println(min2);
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
*/