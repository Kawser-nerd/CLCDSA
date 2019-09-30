import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.0000000000");
	
	public int M,Qn;
	public long total;
	public double[][] P;

	public double[] R;

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
					M=Int();
					Qn=Int();
					P=new double[Qn][4];
					int i,j;
					for(i=0;i<Qn;++i)
					for(j=0;j<4;++j) P[i][j]=in.nextDouble();
					
					total=(1L<<(Qn+Qn));
					if(M>=total) 
					{
						out.println("Case #"+cc+": "+fmt.format(1.0));
						continue;
					}

					R=new double[1];
					R[0]=1.0;
					
					int k,x;
					for(i=0;i<Qn;++i)
					{
						double[] T=new double[4*R.length];
						k = 0;
						for(x=0;x<R.length;++x)
						{
							for(j=0;j<4;++j)
							{
								T[k]=R[x]*P[i][j];
								++k;
							}				
						}
						Arrays.sort(T);
						R=trim(T);
					}

					double res=0.0;
					for(i=1;i<=M;++i)
					{
//						res=res*(1.0-R.get(total-i));
						res=res+R[R.length-i];
					}
					out.println("Case #"+cc+": "+fmt.format(res));						
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}

	public double[] trim(double[] T)
	{
		if(T.length<=M) return T;

		double[] R=new double[M];
		int i,k;
		k=1;
		for(i=0;i<M;++i)
		{
			R[i]=T[T.length-k];
			++k;
		}
		return R;
	}
	/*
	public void go(int i,double prob)
	{
		if(i>=Qn)
		{
			R.add(prob);
			return;
		}

		for(int j=0;j<4;++j)
		{
			go(i+1,prob*P[i][j]);
		}
	}
*/
	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new C()).main();
	}
}
