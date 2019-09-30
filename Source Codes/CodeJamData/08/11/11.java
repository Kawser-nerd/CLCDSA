import java.io.*;
import java.util.*;
import java.math.*;

public class A
{
	public static void main(String[] args) throws Throwable
	{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader("A-small.in")));
		// BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		in.nextToken();
		int t = (int)in.nval, iter = 0;
		while(t-->0)
		{
			iter++;
			in.nextToken();
			int N = (int)in.nval;
			int[] A = new int[N], B = new int[N];
			for(int i = 0; i < N; i++)
			{
				in.nextToken();
				A[i] = (int)in.nval;
			}
			for(int i = 0; i < N; i++)
			{
				in.nextToken();
				B[i] = (int)in.nval;
			}
			Arrays.sort(A);
			Arrays.sort(B);
			BigInteger x = BigInteger.ZERO;
			for(int i = 0; i < N; i++)
				x = x.add(new BigInteger(""+((long)A[i]*(long)B[N-i-1])));
			out.println("Case #"+iter+": "+x);
		}
		out.close();
		System.exit(0);
	}
}