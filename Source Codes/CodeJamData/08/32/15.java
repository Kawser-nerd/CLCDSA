import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class B {
	
	public static void main(String[] args) {
		new B().solve();
	}

	Scanner sc;
	private void solve() {
		try {
			sc = new Scanner(new File("b.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		int N = sc.nextInt(); sc.nextLine();
		
		for (int n = 0; n < N; n++) {
			System.out.print("Case #" + (n + 1) + ": ");
			solveTest();
		}
	}

	private void solveTest() {
		String s = sc.nextLine();
		
		BigInteger[][][][] d = new BigInteger[41][10][3][7];
		for (int i = 0; i <= s.length(); i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 7; l++) {
						d[i][j][k][l] = BigInteger.ZERO;
					}					
				}
			}
		}
		d[0][0][0][0] = BigInteger.ONE;
		
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 7; l++) {
						if (!d[i][j][k][l].equals(BigInteger.ZERO)) {
							int m10 = 0;
							int m3 = 0;
							int m7 = 0;
							
							for (int p = i; p < s.length(); p++) {
								int next = s.charAt(p) - '0';
								m10 = next;
								m3 = (m3 + next) % 3;
								m7 = (m7 * 10 + next) % 7;
								
								// plus
								d[p + 1][(j + m10) % 10][(k + m3) % 3][(l + m7) % 7] = d[p + 1][(j + m10) % 10][(k + m3) % 3][(l + m7) % 7].add(d[i][j][k][l]);
								
								if (i != 0) {
									// minus
									d[p + 1][(j - m10 + 10 + 10) % 10][(k - m3 + 3 + 3) % 3][(l - m7 + 7 + 7) % 7] = d[p + 1][(j - m10 + 10 + 10) % 10][(k - m3 + 3 + 3) % 3][(l - m7 + 7 + 7) % 7].add(d[i][j][k][l]);
								}
							}
						}
					}					
				}
			}
		}
		
		BigInteger ans = BigInteger.ZERO;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 7; l++) {
					if (((j % 2) != 0) && ((j % 5) != 0) && (k != 0) && (l != 0)) {
						continue;
					}
					
					ans = ans.add(d[s.length()][j][k][l]);
				}					
			}
		}
		
		System.out.println(ans);

	}

}
