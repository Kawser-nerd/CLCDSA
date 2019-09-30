import java.io.*;
import java.util.*;
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
	void solve1() throws IOException
	{
		int m=in.readInt();
		int n=in.readInt();
		int[][] a=new int[m][n];
		for(int i=0;i<m;i++)
		{
			String s=in.readString();
			for(int j=0;j<n;j++)
			{
				if(s.charAt(j)=='.')
				{
					a[i][j]=0;
				}
				else
				{
					a[i][j]=1;
				}
			}
		}
		int[][] dp=new int[n][1<<m];
		for(int i=0;i<(1<<m);i++)
		{
			int c=0;
			boolean flag=true;
			for(int j=0;j<m;j++)
			{
				if(((i>>j)%2)==1)
				{
					c++;
					if(a[j][0]==1)
					{
						flag=false;
					}
				}
			}
			if(flag)
			{
				dp[0][i]=c;
			}
			else
			{
				dp[0][i]=0;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<(1<<m);j++)
			{
				int max=0;
				for(int k=0;k<(1<<m);k++)
				{
					int c=0;
					boolean flag=true;
					for(int l=0;l<m;l++)
					{
						if(((j>>l)%2)==1)
						{
							c++;
							if(a[l][i]==1)
							{
								flag=false;
							}
							if((k>>l)%2==1)
							{
								flag=false;
								//System.out.println("df");
							}
							if(l>=1 && (k>>(l-1))%2==1)
							{
								flag=false;
								//System.out.println("df");
							}
							if(l+1<m && (k>>(l+1))%2==1)
							{
								flag=false;
								//System.out.println("df");
							}
						}
					}
					if(flag)
					{
						if(c+dp[i-1][k]>max)
						{
							max=c+dp[i-1][k];
						}
					}
				}
				dp[i][j]=max;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<(1<<m);j++)
			{
				//System.out.printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
			}
		}
		int ma=0;
		for(int i=0;i<(1<<m);i++)
		{
			if(dp[n-1][i]>ma)
			{
				ma=dp[n-1][i];
			}
		}
		out.println(ma);
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
class P1
{
	static int p=10007;
	static Input in=new Input();
	static PrintStream out;
	int[] inv;
	int[] fac;
	void init()
	{
		inv=new int[p];
		fac=new int[p];
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
		fac[0]=1;
		for(int i=1;i<p;i++)
		{
			fac[i]=(fac[i-1]*i)%p;
		}
	}
	int comb1(int m,int n)
	{
		if(m<n)
		{
			return 0;
		}
		return (((fac[m]*inv[fac[n]])%p)*inv[fac[m-n]])%p;
	}
	int comb(int m,int n)
	{
		int m1=m/p;
		int m0=m%p;
		int n1=n/p;
		int n0=n%p;
		return (comb1(m1,n1)*comb1(m0,n0))%p;
	}
	void solve2() throws IOException
	{
		int w=in.readInt();
		int h=in.readInt();
		int r=in.readInt();
		int[] x=new int[r];
		int[] y=new int[r];
		for(int i=0;i<r;i++)
		{
			x[i]=in.readInt();
			y[i]=in.readInt();
		}
		if((w+h-2)%3!=0)
		{
			out.println("0");
			return;
		}
		int a=(2*(w-1)-(h-1))/3;
		int b=(2*(h-1)-(w-1))/3;
		if(a<0 || b<0)
		{
			out.println("0");
			return;
		}
		int n=0;
		int[] s=new int[r];
		int[] t=new int[r];
		for(int i=0;i<r;i++)
		{
			//System.out.printf("x,y: %d %d\n", x[i],y[i]);
			if(((x[i]+y[i]-2)%3)!=0)
			{
				continue;
			}
			int s1=((2*(x[i]-1)-(y[i]-1)))/3;
			int t1=((2*(y[i]-1)-(x[i]-1)))/3;
			if(s1<0 || t1<0 || s1>a || t1>b)
			{
				continue;
			}
			s[n]=s1;
			t[n]=t1;
			n++;
		}
		a++;
		b++;
		//a,b,s[],t[]
		int[][] ba=new int[a][b];
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				ba[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			ba[s[i]][t[i]]=1;
		}
		int[][] dp=new int[a][b];
		dp[0][0]=1;
		for(int i=1;i<b;i++)
		{
			if(ba[0][i]==1)
			{
				dp[0][i]=0;
				continue;
			}
			dp[0][i]=dp[0][i-1];
		}
		for(int i=1;i<a;i++)
		{
			if(ba[i][0]==1)
			{
				dp[i][0]=0;
				continue;
			}
			dp[i][0]=dp[i-1][0];
		}
		for(int i=1;i<a;i++)
		{
			for(int j=1;j<b;j++)
			{
				if(ba[i][j]==1)
				{
					dp[i][j]=0;
				}
				else
				{
					dp[i][j]=(dp[i-1][j]+dp[i][j-1])%p;
				}
			}
		}
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				//System.out.printf("dp: %d %d %d %d\n", i,j,ba[i][j],dp[i][j]);
			}
		}
		System.out.println(dp[a-1][b-1]);
	}
	void solve1() throws IOException
	{
		int w=in.readInt();
		int h=in.readInt();
		int r=in.readInt();
		int[] x=new int[r];
		int[] y=new int[r];
		for(int i=0;i<r;i++)
		{
			x[i]=in.readInt();
			y[i]=in.readInt();
		}
		if((w+h-2)%3!=0)
		{
			out.println("0");
			return;
		}
		int a=(2*(w-1)-(h-1))/3;
		int b=(2*(h-1)-(w-1))/3;
		if(a<0 || b<0)
		{
			out.println("0");
			return;
		}
		int n=0;
		int[] s=new int[r];
		int[] t=new int[r];
		for(int i=0;i<r;i++)
		{
			//System.out.printf("x,y: %d %d\n", x[i],y[i]);
			if(((x[i]+y[i]-2)%3)!=0)
			{
				continue;
			}
			int s1=((2*(x[i]-1)-(y[i]-1)))/3;
			int t1=((2*(y[i]-1)-(x[i]-1)))/3;
			if(s1<0 || t1<0 || s1>a || t1>b)
			{
				continue;
			}
			s[n]=s1;
			t[n]=t1;
			n++;
		}
		//System.out.printf("n: %d\n",n);
		for(int i=0;i<n;i++)
		{
			//System.out.printf("barrier: %d %d\n", s[i],t[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s[i]>s[j] || (s[i]==s[j] && t[i]>t[j]))
				{
					int u=s[i];
					s[i]=s[j];
					s[j]=u;
					u=t[i];
					t[i]=t[j];
					t[j]=u;
				}
			}
		}
		//System.out.printf("a,b: %d %d\n",a,b);
		for(int i=0;i<n;i++)
		{
			//System.out.printf("barrier: %d %d\n", s[i],t[i]);
		}
		//a,b,s[],t[],n
		int rr=0;
		for(int i=0;i<(1<<n);i++)
		{
			int cx=0;
			int cy=0;
			int cp=1;
			int cm=1;
			for(int j=0;j<n;j++)
			{
				int d=(i>>j)%2;
				if(d==1)
				{
					cm=-cm;
					int nx=s[j];
					int ny=t[j];
					if(nx>=cx && ny>=cy)
					{
						cp=cp*comb(nx+ny-cx-cy,nx-cx);
						cp=cp%p;
					}
					else
					{
						cp=0;
					}
					cx=nx;
					cy=ny;
				}
			}
			cp=cp*comb(a+b-cx-cy,a-cx);
			cp=cp%p;
			int cr=(((cp*cm)%p)+p)%p;
			rr=(rr+cr)%p;
			rr=(rr+p)%p;
			//System.out.printf("i,cr: %d %d\n", i,cr);
		}
		out.println(rr);
	}
	public void solve() throws IOException
	{
		init();
		out=System.out;
		int n=in.readInt();
		for(int i=0;i<n;i++)
		{
			out.printf("Case #%d: ", i+1);
			solve1();
			//solve2();
		}
		out.close();
	}
}
class P
{
	static Input in=new Input();
	static PrintStream out;
	void solve1() throws IOException
	{
		
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
class Input
{
	BufferedReader reader;
	LinkedList<String> strings;
	public Input(String filename) throws IOException
	{
		reader=new BufferedReader(new FileReader(filename));
		strings=new LinkedList<String>();
	}
	public Input()
	{
		reader=new BufferedReader(new InputStreamReader(System.in));
		strings=new LinkedList<String>();
	}
	public void close() throws IOException
	{
		reader.close();
	}
	void check() throws IOException
	{
		while(strings.size()==0)
		{
			String s=reader.readLine();
			String[] ss=s.split(" ");
			for(int i=0;i<ss.length;i++)
			{
				strings.addLast(ss[i]);
			}
		}
		while(strings.getFirst().length()==0)
		{
			strings.removeFirst();
		}
	}
	public String readString() throws IOException
	{
		check();
		//System.out.println(strings.getFirst());
		return strings.removeFirst();
	}
	public int readInt() throws IOException
	{
		return Integer.parseInt(readString());
	}
	public long readLong() throws IOException
	{
		return Long.parseLong(readString());
	}
	public double readDouble() throws IOException
	{
		return Double.parseDouble(readString());
	}
	public String readLine() throws IOException
	{
		check();
		String r="";
		while(strings.size()>0)
		{
			r+=(strings.removeFirst());
			if(strings.size()==0)
			{
				break;
			}
			r+=" ";
		}
		return r;
	}
}