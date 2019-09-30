import java.math.BigInteger;
import java.util.Scanner;

public class R1B_A {
	public static void main(String[] args) {
		final int MAX = 100000;
		long[][] pascal = new long[MAX+1][4];
		pascal[0][0] = 1;
		for (int i = 1; i <= MAX; ++i) {
			pascal[i][0] = 1;
			for (int j = 1; j <= 3; ++j) {
				pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
			}
		}
		
		Scanner scin = new Scanner(System.in);
		int N = scin.nextInt();
		for (int z = 1; z <= N; ++z) {
			int n = scin.nextInt();
			long A = scin.nextLong();
			long B = scin.nextLong();
			long C = scin.nextLong();
			long D = scin.nextLong();
			long x0 = scin.nextLong();
			long y0 = scin.nextLong();
			long M = scin.nextLong();
			long x = x0, y = y0;
			
			int[] coords = new int[9];
			coords[(int)((x%3)*3 + (y%3))]++;
			for (int i = 1; i < n; ++i) {
				x = (A * x + B)%M;
				y = (C * y + D)%M;
				coords[(int)((x%3)*3 + (y%3))]++;
			}
			
			BigInteger ans = BigInteger.ZERO;
			for (int i = 0; i < 9; ++i) {
				for (int j = i+1; j < 9; ++j) {
					for (int k = j+1; k < 9; ++k) {
						if ((i/3 + j/3 + k/3)%3 == 0 && (i%3 + j%3 + k%3)%3 == 0) {
							ans = ans.add(new BigInteger("" + ((long)coords[i])*((long)coords[j])*coords[k]));
						}
					}
					if (((i/3)*2 + j/3)%3 == 0 && ((i%3)*2 + j%3)%3 == 0) {
						ans = ans.add(new BigInteger("" + pascal[coords[i]][2]).multiply(new BigInteger("" + coords[j])));
					}
					if ((i/3 + (j/3)*2)%3 == 0 && (i%3 + (j%3)*2)%3 == 0) {
						ans = ans.add(new BigInteger("" + coords[i]).multiply(new BigInteger("" + pascal[coords[j]][2])));
					}
				}
				ans = ans.add(new BigInteger("" + pascal[coords[i]][3]));
			}
			System.out.println("Case #" + z + ": " + ans);
		}
	}
}
