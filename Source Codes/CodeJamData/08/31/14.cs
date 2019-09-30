using System;
using System.IO;
class program
{
	static int solve(int p,int k,int l,int[] q)
	{	
		int j=k;
		int c=1;
		int ans=0;
    Array.Sort<int>(q);
		for (int i=0;i<l;i++)
		{	
			if (j==0)
			{
				j=k;
				c++;	
			}
			j--;
			ans+=c*q[l-i-1];
		}
		return ans;
	}
	static void Main()
	{
		StreamReader sr=new StreamReader("a-small.in");
		var sw=new StreamWriter("a-small.out");				
		int Tst=int.Parse(sr.ReadLine());
		for (int tst=0;tst<Tst;tst++)
		{
			string[] s=sr.ReadLine().Split(' ');			
			string[] ss=sr.ReadLine().Split(' ');
			int[] q=new int[ss.Length];
			for (int i=0;i<ss.Length;i++)
			{
				q[i]=int.Parse(ss[i]);
			}			
			sw.WriteLine("Case #{0}: {1}",tst+1,solve(int.Parse(s[0]),int.Parse(s[1]),int.Parse(s[2]),q));
		}		
		sw.Close();	
		sr.Close();
	}
}
