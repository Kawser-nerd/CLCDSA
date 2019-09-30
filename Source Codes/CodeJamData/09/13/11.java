import java.io.*;
import java.util.*;
public class a {
	public static void main(String[] args) throws Exception
	{
		P3 p=new P3();
		p.solve();
	}
}
class P1
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private void solve1() throws Exception
	{
		
	}

}
class P2
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private void solve1() throws Exception
	{
		
	}

}
class P3
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private double factorial(int n)
	{
		double r=1;
		for(int i=1;i<=n;i++)
		{
			r*=i;
		}
		return r;
	}
	private double choose(int n,int k)
	{
		if(k<0)
		{
			return 0;
		}
		if(n<k)
		{
			return 0;
		}
		if(k==0)
		{
			return 1;
		}
		if(n==k)
		{
			return 1;
		}
		return factorial(n)/(factorial(k)*factorial(n-k));
	}
	private double f(int n,int m,int c,int i)
	{
		return choose(n-m,i)*choose(m,c-i)/choose(n,c);
	}
	private void solve1() throws Exception
	{
		int n=sc.nextInt();
		int c=sc.nextInt();
		double[] p=new double[n+1];
		//System.out.println(f(3,2,2,0));
		//System.out.println(choose(1,0));
		//System.out.println(choose(2,2));
		//System.out.println(choose(3,2));
		//System.out.println(factorial(3));
		//System.out.println(factorial(2));
		p[n]=0;
		for(int m=n-1;m>=0;m--)
		{
			double denominator=1-f(n,m,c,0);
			double numerator=1;
			for(int i=1;i<=c;i++)
			{
				if(m+i<=n)
				{
					numerator+=(f(n,m,c,i)*p[m+i]);
				}
			}
			p[m]=numerator/denominator;
			//System.out.println(" "+m+" "+p[m]+" "+numerator+" "+denominator);
		}
		System.out.println(p[0]);
	}

}
class P4
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private void solve1() throws Exception
	{
		
	}

}