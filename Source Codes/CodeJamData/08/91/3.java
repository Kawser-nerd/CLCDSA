import java.io.*;
import java.util.*;
import java.text.*;

public class A
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public TreeSet<Integer> Aval,Bval,Cval;
	
	public static int ID = 0;

	private class Person implements Comparable<Person>
	{
		public int A,B,C;
		public int index;
		public Person(int aa,int bb,int cc)
		{
			A=aa; B=bb; C=cc;
			index = ID++;
			//out.println("A = "+A+", B = "+B+", C = "+C+", index = "+index);
		}

		public int count(int a,int b,int c)
		{
			return (A<=a && B<=b && C<=c)?1:0;
		}

		public int compareTo(Person u)
		{
			return index-u.index;
		}
	}

	public Person[] p;
	public int n;

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
					n=Int();
					Aval=new TreeSet<Integer>();
					Bval=new TreeSet<Integer>();
					Cval=new TreeSet<Integer>();
					
					p=new Person[n];
					for(int i=0;i<n;++i)
					{
						int A,B,C;
						A=Int(); B=Int(); C=Int();
						p[i]=new Person(A,B,C);

						Aval.add(A);
						Bval.add(B);
						Cval.add(C);
					}

					int res = 0;
					
					//int[] av = setI2ia(Aval);
					//int[] bv = setI2ia(Bval);
					
					int a,b,c,cnt;
					//sort by a
					Arrays.sort(p,new CmpA());
					for(int i=0;i<p.length;++i)
					{
						a = p[i].A;
						Person[] v = extract(p,0,i);
						
						Arrays.sort(v,new CmpB());
						TreeSet<Person> T=new TreeSet<Person>(new CmpCRev());

						//filter a --> sort by B
						for(int j=0;j<v.length;++j)
						{
							//filter b, 
							b=v[j].B;
							T.add(v[j]);
							
							if(a+b<=10000)
							{
								c = 10000 - a - b;
								while(!T.isEmpty() && T.first().C>c)
								{
									T.remove(T.first());
								}
								res=Math.max(res,T.size());
							}
							else break;
						}
					}
					err.println("Case #"+cc+": "+res);

					out.println("Case #"+cc+": "+res);
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}

	public Person[] extract(Person[] p,int i,int j)
	{
		Person[] ret=new Person[j-i+1];
		int x=0;
		while(i<=j)
		{
			ret[x++]=p[i];
			++i;
		}
		return ret;
	}

	public class CmpA implements Comparator<Person>
	{
		public int compare(Person X,Person Y)
		{
			if(X.A != Y.A) return X.A - Y.A;
			return X.compareTo(Y);
		}
	}

	public class CmpB implements Comparator<Person>
	{
		public int compare(Person X,Person Y)
		{
			if(X.B != Y.B) return X.B - Y.B;
			return X.compareTo(Y);
		}
	}	

	public class CmpCRev implements Comparator<Person>
	{
		public int compare(Person X,Person Y)
		{
			if(X.C != Y.C) return -(X.C - Y.C);
			return X.compareTo(Y);
		}
	}


	public int[] setI2ia(TreeSet<Integer> S)
	{
		int[] ret=new int[S.size()];
		int i=0;
		for(Integer x : S)
		{
			ret[i] = x;
			++i;
		}
		return ret;
	}

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new A()).main();
	}
}


