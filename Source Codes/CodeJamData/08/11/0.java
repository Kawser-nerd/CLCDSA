import java.io.*;
import java.util.*;
import library.*;
class Main
{
	public static void main(String[] args) throws IOException
	{
		P1 p=new P1();
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