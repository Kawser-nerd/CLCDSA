import java.io.*;
import java.util.*;
import java.text.*;

public class A
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public int n;
	public TreeMap<String,Integer> ID;
	public TreeMap<String,Mixture> Mix;
	public Mixture[] v;

	private class Mixture
	{
		public Mixture[] c;
		public int cn;
		public int bowl,index;
		public String name;
		public String[] cname;

		public Mixture(String nameIn,int i,ArrayList<String> A)
		{
			name=nameIn;
			index=i;
			bowl=-1;
			
			cname=A.toArray(new String[0]);
		}

		public void finalize()
		{
			int x;
			cn=cname.length;
			c=new Mixture[cn];
			for(x=0;x<cn;++x)
			{
				c[x]=Mix.get(cname[x]);
			}
		}

		public int solve()
		{
			if(bowl>=0) return bowl;
			int val = 0;
			int cnt = 0;

			int i,j,k;
			int[] T=new int[cn];
			for(i=0;i<cn;++i)
			{
				T[i]=c[i].solve();
			}

			Arrays.sort(T);
			cnt = 0;
			for(i=cn-1;i>=0;--i)
			{
				val=Math.max(val,cnt+T[i]);
				++cnt;
			}
			val=Math.max(val,cnt+1);
			//err.println(name+"-->"+val);
			return bowl=val;
		}
	}

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
				int TCase,cc;
				
				long startTime=System.currentTimeMillis();
				
				TCase=in.nextInt();
				for(cc=1;cc<=TCase;++cc)
				{
					//read
					n=Int();
					v=new Mixture[n];
					ArrayList<String> A;

					for(int i=0;i<n;++i)
					{
						A=new ArrayList<String>();
						String name=Token();
						int Tn=Int();
						for(int j=0;j<Tn;++j)
						{
							String str=Token();
							if(isUpper(str.charAt(0)))
							{
								A.add(str);
							}
						}
						v[i]=new Mixture(name,i,A);
					}

					//name ID+Mix
					ID=new TreeMap<String,Integer>();
					Mix=new TreeMap<String,Mixture>();
					int i,j,k;
					for(i=0;i<n;++i)
					{
						ID.put(v[i].name,i);
						Mix.put(v[i].name,v[i]);
					}					
					//finalize
					for(i=0;i<n;++i)
					{
						v[i].finalize();
					}
					out.println("Case #"+cc+": "+v[0].solve());
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}

	public boolean isUpper(char c) { return 'A'<=c && c<='Z'; }
	public boolean isLower(char c) { return 'a'<=c && c<='z'; }	
	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new A()).main();
	}
}
