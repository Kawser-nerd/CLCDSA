import java.util.Arrays;
import java.util.Scanner;

public class C
{

	public static void main(String[] args) throws Exception
	{
		new C();
	}
	
	final int oo = (int)1e9;
	double[][] choose = new double[50][50];
	
	int N,C;
	double D;
	
	double[] memo = new double[50];
	
	C() throws Exception
	{
		for (double[] c : choose) Arrays.fill(c, -1);
		Scanner in = new Scanner(System.in);
		for (int T=in.nextInt(),ds=1; T-->0; ++ds)
		{
			C = in.nextInt();
			N = in.nextInt();
			D = choose(C,N);
			Arrays.fill(memo, -1);
			System.out.printf("Case #%d: %.9f%n", ds,go(0));
		}
	}
	
	double go(int X)
	{
		if (X==C)
			return 0;
		if (memo[X] > -0.5)
			return memo[X];
		double exp = 1;
		for (int i=1; i<=N; ++i)
		{
			if (X+i>C) break;
			exp += choose(X,N-i)*choose(C-X,i)/D*go(X+i);
		}
		exp /= (1-choose(X,N)*choose(C-X,0)/D);
		return memo[X] = exp;
	}
	
	double choose(int n, int k)
	{
		if (k==0 || n==k)
			return 1;
		if (n<k)
			return 0;
		if (choose[n][k] > -0.5)
			return choose[n][k];
		return choose[n][k] = choose(n-1,k-1)+choose(n-1,k);
	}

}
