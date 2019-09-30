package round2;

import java.util.Scanner;

public class D {
	static long MOD = 1000000007L;
	static int R, C;
	
	static long[][][][] table;
	
	static long calc(int r, int may3, int mayOther, int mcm) {
		long ret = table[r][may3][mayOther][mcm];
		if (ret != -1) return ret;
		if (r == 0) return table[r][may3][mayOther][mcm] = 1;
		ret = 0;
		if (r >= 2 && may3 == 1) {
			ret += calc(r-2, 0, 1, mcm);
			ret %= MOD;
		}
		if (r >= 1 && mayOther == 1) {
			ret += calc(r-1, 1, 0, mcm);
		}
		if (r >= 2 && mayOther == 1) {
			for (int period = 3; period < 7; period += 3) if (C % period == 0) {
				long gcd = gcd(period, mcm);
				long nmcm = period / gcd * mcm;
				long val = calc(r-2, 1, 0, (int)nmcm);
				ret += gcd * val;
				ret %= MOD;
			}
		}
		if (r >= 3 && mayOther == 1 && C % 4 == 0) {
			long gcd = gcd(4, mcm);
			long nmcm = 4 / gcd * mcm;
			long val = calc(r-3, 1, 0, (int)nmcm);
			ret += gcd * val;
			ret %= MOD;
		}
		
		return table[r][may3][mayOther][mcm] = ret;
	}
	
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			R = sc.nextInt();
			C = sc.nextInt();
			table = new long[R+1][2][2][13]; 
			for (int i = 0; i < table.length; i++) {
				for (int j = 0; j < table[i].length; j++) {
					for (int j2 = 0; j2 < table[i][j].length; j2++) {
						for (int k = 0; k < table[i][j][j2].length; k++) {
							table[i][j][j2][k] = -1;
						}
					}
				}
			}
			
			System.out.println("Case #" + caze + ": " + calc(R, 1, 1, 1));
		}
	}

}
