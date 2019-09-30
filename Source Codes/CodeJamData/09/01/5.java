import java.io.*;
import java.util.*;
import java.text.*;

public class A
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000");
	
	public int L, D;
	public DTree root;

	private class DTree
	{
		public DTree[] c;
		
		public DTree()
		{
			c = new DTree[26];
		}

		public void insert(char[] w, int i)
		{
			if(i >= w.length) return;

			int x = w[i]-'a';
			if(c[x] == null) c[x] = new DTree();
			c[x].insert(w, i+1);
		}

		public int count(char[] p, int i)
		{
			if(i >= p.length) return 1;
			int x, sum, j;

			if(p[i]=='(')
			{
				sum = 0;
				j = i+1;
				while(p[j]!=')') ++j;

				for(int k=i+1;k<j;++k)
				{
					x = p[k]-'a';
					if(c[x] == null) continue;
					sum += c[x].count(p, j+1);
				}

				return sum;
			}
			else
			{
				//single letter
				x = p[i]-'a';
				if(c[x]==null) return 0;
				return c[x].count(p, i+1);
			}
		}
	}

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
			int TCase,cc;
			
			L = in.nextInt();
			D = Int();
			TCase = in.nextInt();
			
			char[] word, p;

			root = new DTree();
			for(int i=0;i<D;++i)
			{
				word = Token().toCharArray();
				root.insert(word, 0);
			}

			for(cc=1;cc<=TCase;++cc)
			{
				p = Token().toCharArray();
				out.println("Case #"+cc+": " + root.count(p,0));
			}
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime=System.currentTimeMillis();

		(new A()).main();

		System.err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"(ms)");
	}
}

