import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		int N = in.nextInt();
		int pr[] = new int[15];
		pr[0] = 2;
		pr[1] = 3;
		pr[2] = 5;
		pr[3] = 7;
		pr[4] = 2*3;
		pr[5] = 2*5;
		pr[6] = 2*7;
		pr[7] = 3*5;
		pr[8] = 3*7;
		pr[9] = 5*7;
		pr[10] = 3*5*7;
		pr[11] = 2*5*7;
		pr[12] = 2*3*7;
		pr[13] = 2*3*5;
		pr[14] = 2*3*5*7;
		for (int case_no = 1; case_no <= N; case_no++)
		{
			String str = in.next();
			int L = str.length();
			BigInteger res[][][] = new BigInteger[L+1][15][2*3*5*7];
			for (int i = 0; i <= L; i++)
			{
				for (int j = 0; j < 15; j++)
				{
					for (int k = 0; k < pr[j]; k++)
					{
						if (i == 0)
						{
							if (k == 0)	
								res[i][j][k] = BigInteger.ONE;
							else
								res[i][j][k] = BigInteger.ZERO;
						}
						else
						{
							res[i][j][k] = BigInteger.ZERO;
							for (int l = 0; l < i; l++)
							{
								int m = (new BigInteger(str.substring(l, i))).mod(BigInteger.valueOf(pr[j])).intValue();
								res[i][j][k] = res[i][j][k].add(res[l][j][(k-m+pr[j])%pr[j]]);
								if (l!=0)
									res[i][j][k] = res[i][j][k].add(res[l][j][(k+m)%pr[j]]);
							}
						}
					}
				}
			}
			BigInteger final_res = res[L][0][0].add(res[L][1][0]).add(res[L][2][0]).add(res[L][3][0]);
			final_res = final_res.subtract(res[L][4][0]).subtract(res[L][5][0]).subtract(res[L][6][0]).subtract(res[L][7][0]).subtract(res[L][8][0]).subtract(res[L][9][0]);
			final_res = final_res.add(res[L][10][0]).add(res[L][11][0]).add(res[L][12][0]).add(res[L][13][0]);
			final_res = final_res.subtract(res[L][14][0]);
			out.print("Case #");
			out.print(case_no);
			out.print(": ");
			out.println(final_res.toString());
		}
		out.flush();
	}

}
