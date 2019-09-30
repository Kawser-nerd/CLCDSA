using System;
using System.IO;
class program
{
  static int qwe(string s)
	{
		int ans=0;
		for(int i=0;i<s.Length;i++)
		{
			ans=(ans*10+int.Parse(s[i].ToString()))%210;
		}
		return ans;
	}
	static long solve(string s)
	{
	checked
{
		int l=s.Length;
		long[,,] d=new long[l,l,210];
		for (int i=0;i<l;i++)
		{
			d[i,i,int.Parse(s[i].ToString())]=1;
		}
		for (int i=1;i<l;i++)
		{ 
			for (int j=0;j<l-i;j++)
			{
				d[j,j+i,qwe(s.Substring(j,i+1))]=1;
				for (int k=0;k<i;k++)
				{
					int c2=qwe(s.Substring(j+k+1,i-k));
					for (int c1=0;c1<210;c1++)
					{
/*						for (int c2=0;c2<210;c2++)
						{
							 d[j,j+i,(c1+c2)%210]+=d[j,j+k,c1]*d[j+k+1,j+i,c2];
							 d[j,j+i,(210+c1-c2)%210]+=d[j,j+k,c1]*d[j+k+1,j+i,c2];
						}*/
 					 	d[j,j+i,(c1+c2)%210]+=d[j,j+k,c1];
 					 	d[j,j+i,(210+c1-c2)%210]+=d[j,j+k,c1];
					}
				}
			}			
		}
		long ans=0;
		for (int i=0;i<210;i++)
		{
			if ((i%2)*(i%3)*(i%5)*(i%7)==0) ans+=d[0,l-1,i];
		}
		return ans;
}	}
	static void Main()
	{
		StreamReader sr=new StreamReader("b-small.in");
		var sw=new StreamWriter("b-small.out");				
		int Tst=int.Parse(sr.ReadLine());
		for (int tst=0;tst<Tst;tst++)
		{
			string s=sr.ReadLine();		
			sw.WriteLine("Case #{0}: {1}",tst+1,solve(s));
		}		
		sw.Close();	
		sr.Close();
	}
}
