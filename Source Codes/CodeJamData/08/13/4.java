import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class C_big {

	public long[][] power(long[][] a, long pow, long mod)	{	
		if (pow == 0)	{
			int n = a.length;
			long[][] ret = new long[n][n];
			for (int i = 0; i < n; i++)	ret[i][i] = 1;
			return ret;
		}
		if (pow == 1)	return a;

		long[][] temp1 = power(a, pow/2, mod);
		temp1 = matrixMultiply(temp1, temp1, mod);

		if (pow % 2 == 1)	return matrixMultiply(temp1, a, mod);
		else	return temp1;
	}


	public long[][] matrixMultiply(long[][] a, long[][] b, long mod)	{
		int n = a.length;
		int m = b.length;
		int p = b[0].length;
		long[][] c = new long[n][p];

		int i, j, k;
		long s;
		for (i = 0; i < n; i++)		{
			for (j = 0; j < p; j++)			{
				s = 0;
				for (k = 0; k < m; k++)		s = (s + (a[i][k]*b[k][j])) % mod;
				c[i][j] = s % mod;
			}
		}
		return c;
	}


	void run()	{
		long[][] mat = new long[2][2];
		mat[0][0] = 6;
		mat[0][1] = 996;
		mat[1][0] = 1;
		mat[1][1] = 0;

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int nc = 1; nc <= T; nc++)		{
			int n = sc.nextInt();
			
			long[][] foo = power(mat, n-1, 1000);
			long ans = (foo[0][0] * 6 + foo[0][1] * 2) % 1000;

			if (ans == 0)	ans = 999;	else	ans--;

			String ret = "" + ans;
			while (ret.length() < 3)	ret = "0" + ret;
			System.out.println("Case #" + nc + ": " + ret);
		}
	}

	public static void main(String[] args)	{
		C_big obj = new C_big();
		obj.run();
	}
}
