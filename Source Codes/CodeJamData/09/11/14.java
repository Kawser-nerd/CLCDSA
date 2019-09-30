import java.io.*;
import java.util.*;
public class a {
	public static void main(String[] args) throws Exception
	{
		P1 p=new P1();
		p.solve();
	}
}
class P1
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		sc.nextLine();
		this.precompute();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private int step(int n,int base)
	{
		int r=0;
		while(n>0)
		{
			r+=((n%base)*(n%base));
			n/=base;
		}
		return r;
	}
	private boolean isHappy(int n,int base)
	{
		HashSet<Integer> s=new HashSet<Integer>();
		while(true)
		{
			if(n==1)
			{
				return true;
			}
			if(s.contains(n))
			{
				return false;
			}
			s.add(n);
			n=step(n,base);
		}
	}
	private int[] sieve(int[] a,int base)
	{
		int N=a.length;
		int[] b=new int[N];
		int j=0;
		for(int i=0;i<N;i++)
		{
			if(this.isHappy(a[i], base))
			{
				b[j]=a[i];
				j++;
			}
		}
		int[] c=new int[j];
		for(int i=0;i<j;i++)
		{
			c[i]=b[i];
		}
		return c;
	}
	private int[] test(int N,int[] b)
	{
		int[] a=new int[N];
		for(int i=0;i<N;i++)
		{
			a[i]=i+2;
		}
		for(int i=0;i<b.length;i++)
		{
			a=this.sieve(a, b[i]);
		}
		//System.out.println(a.length);
		//if(a.length>1)
		//{
		//	System.out.println(a[1]);
		//}
		return a;
	}
	private int[] test10(int N,int[] b)
	{
		int j=0;
		int[] a=new int[N];
		for(int i=0;i<N;i++)
		{
			a[i]=pre[i];
		}
		for(int i=0;i<b.length;i++)
		{
			a=this.sieve(a, b[i]);
		}
		//System.out.println(a.length);
		//if(a.length>1)
		//{
		//	System.out.println(a[1]);
		//}
		return a;
	}
	int[] pre;
	private void precompute()
	{
		int N=50000;
		int j=0;
		int[] a=new int[N];
		for(int i=2;;i++)
		{
			if(this.isHappy(i, 10))
			{
				a[j]=i;
				j++;
			}
			if(j==N)
			{
				break;
			}
		}
		pre=a;
		//System.out.println("pre completed");
	}
	private void solve1() throws Exception
	{
		String s=sc.nextLine();
		String[] ss=s.split(" ");
		int n=ss.length;
		int[] b=new int[n];
		for(int i=0;i<n;i++)
		{
			b[i]=Integer.parseInt(ss[i]);
		}
		Arrays.sort(b);
		//System.out.println(b[b.length-1]);
		if(b[n-1]==10)
		{
			for(int m=50;;m*=10)
			{
				int[] a=this.test10(m,b);
				if(a.length>0)
				{
					System.out.println(a[0]);
					break;
				}
			}
		}
		else
		{
			for(int m=50;;m*=10)
			{
				int[] a=this.test(m,b);
				if(a.length>0)
				{
					System.out.println(a[0]);
					break;
				}
			}
		}
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