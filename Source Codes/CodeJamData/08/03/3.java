import java.io.*;
import java.util.*;
import library.*;
class Main
{
	public static void main(String[] args) throws IOException
	{
		P3 p=new P3();
		p.solve();
	}
}
class P3
{
	static Input in=new Input();
	static PrintStream out;
	double circle(double x)
	{
		double y=Math.sqrt(1-x*x);
		return (Math.acos(x)-x*y)/2;
	}
	double f1(double x,double y)
	{
		if(x*x+y*y>=1)
		{
			return 0;
		}
		double x2=Math.sqrt(1-y*y);
		return circle(x)-circle(x2)-(x2-x)*y;
	}
	double f2(double x1,double x2,double y1,double y2)
	{
		if(x2*x2+y2*y2<1)
		{
			return (x2-x1)*(y2-y1);
		}
		if(x1*x1+y1*y1>1)
		{
			return 0;
		}
		return f1(x1,y1)+f1(x2,y2)-f1(x1,y2)-f1(x2,y1);
	}
	public void solve1() throws IOException
	{
		double f=in.readDouble();
		double R=in.readDouble();
		double t=in.readDouble();
		double r=in.readDouble();
		double g=in.readDouble();
		double R2=R-t-f;
		double r2=(r+f)/R2;
		double g2=(g-2*f)/R2;
		//System.out.printf("R2,r2,g2=%f %f %f\n",R2,r2,g2);
		if(g2<=0)
		{
			out.println("1.000000");
			return;
		}
		double c=r2+g2+r2;
		int n=(int)(1.0/c+2);
		double total=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				double x1=c*i+r2;
				double y1=c*j+r2;
				double x2=x1+g2;
				double y2=y1+g2;
				total+=f2(x1,x2,y1,y2);
			}
		}
		//System.out.println(total);
		total/=((R*R*Math.PI/4)/(R2*R2));
		out.printf("%.8f\n",1-total);
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
*/

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