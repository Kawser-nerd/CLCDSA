import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigDecimal;


public class Gcj2 {

	/**
	 * @param args
	 */
	static String str;
	static long[][][][][] memo;
	static int limit;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader In = new BufferedReader(new FileReader(new File("c:\\in.txt")));
		BufferedWriter Out = new BufferedWriter(new FileWriter(new File("c:\\out")));

		int n = Integer.parseInt(In.readLine());
		for (int num = 1; num <= n; num++) {
			str = In.readLine();
			limit = str.length();
			memo = new long[limit + 1][2][3][5][7];
			for (int i = 0; i <= limit; i++) {
					for (int a = 0; a < 2; a++) {
						for (int b = 0; b < 3; b++) {
							for (int c = 0; c < 5; c++) {
								for (int d = 0; d < 7; d++) {
									memo[i][a][b][c][d] = -1;
								}
							}
						}
					}
			}
			Out.write("Case #" + num + ": " + dp(0, 0, 0, 0, 0) / 2 + "\n");
		}
		Out.flush();
	}
	public static long dp(int index, int two, int three, int five, int seven) {
		if (memo[index][two][three][five][seven] >= 0)
			return memo[index][two][three][five][seven];
		if (index == limit) {
			if (two == 0 || three == 0 || five == 0 || seven == 0) {
				return memo[index][two][three][five][seven] = 1;
			} else {
				return memo[index][two][three][five][seven] = 0;
			}
		}
		long res = 0;
		for (int i = index; i < limit; i++) {
			res += dp(i + 1, (two + MOD(index, i + 1, 2)) % 2, (three + MOD(index, i + 1, 3)) % 3, (five + MOD(index, i + 1, 5)) % 5, (seven + MOD(index, i + 1, 7)) % 7);
			res += dp(i + 1, (two + 2 - MOD(index, i + 1, 2)) % 2, (three + 3 - MOD(index, i + 1, 3)) % 3, (five + 5 - MOD(index, i + 1, 5)) % 5, (seven + 7 - MOD(index, i + 1, 7)) % 7);
		}	
		return memo[index][two][three][five][seven] = res;
	}
	public static int MOD(int start, int end, int base) {
		int res = 0;
		for (int i = start; i < end; i++) {
			res = ((res * 10) % base + (str.charAt(i) - '0')) % base;
		}
		return res;
	}
}

