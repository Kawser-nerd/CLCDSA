import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public int C, N;
	public double[] E;
	public double[][] memo;

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
			int TCase,cc;
								
			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				C = Int();
				N = Int();

				memo = new double[C+1][N+1];
				init(memo, -1.0);
				
				E = new double[C+1];
				E[0] = 0.0;
				for(int k=1;k<=C;++k)
				{
					double A, B;
					A = 1.0 - p(k, 0);
					B = 1.0;
					for(int i = 1;i<=N && i<=k;++i)
					{
						B += p(k, i)*E[k-i];
					}

					E[k] = B/A;
				}

				out.println("Case #"+cc+": "+fmt.format(E[C]));
			}
				
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public double p(int k, int i)
	{
		if(!(0<=N-i && N-i<=C-k)) return 0.0;
		if(memo[k][i] >= -0.1) return memo[k][i];

		return memo[k][i] = ((double)C(k,i)/(double)C(C,N))*(C(C-k, N-i));
	}

	public void init(double[][] A, double val)
	{ 
		for(int i=0;i<A.length;++i) Arrays.fill(A[i], val); 
	}

	//Combination C(n, r)
	//CMax = maximum value for n
	//CRMax = maximum value for r
	//This method is initialized when first used.
	public int CMax = 41;
	public int CRMax = 41;
	public long[][] CMem;
	//public int[][] CMem;

	public long C(int n, int r)
	{
		if(CMem == null)
		{
			CMem = new long[CMax+1][];
			int i, j, T;

			CMem[0] = new long[]{1};
			for(i=1;i<=CMax;++i)
			{
				T = Math.min(i, CRMax) + 1;
				CMem[i] = new long[T];

				CMem[i][0] = 1;
				if(i<=CRMax) CMem[i][i] = 1;

				for(j=1;j<i && j<=CRMax;++j)
				{
					CMem[i][j] = CMem[i-1][j] + CMem[i-1][j-1];
				}
			}
		}
		return CMem[n][r];
	}//end public int C(int n, int r)


	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime=System.currentTimeMillis();

		(new C()).main();

		System.err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"(ms)");
	}
}