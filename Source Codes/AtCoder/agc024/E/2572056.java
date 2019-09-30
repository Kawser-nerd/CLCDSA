import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	
	static long M;
	static int N, K;
	
	static long[][] comb;
	static long[][] table;
	static long[][] acumTable;
	
	static void calcComb() {
		comb = new long[N + 1][];
		comb[0] = new long[1];
		comb[0][0] = 1;
		for (int i = 1; i <= N; i++) {
			comb[i] = new long[i + 1];
			comb[i][0] = comb[i][i] = 1;
			for (int j = 1; j < i; j++) {
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
			}
		}
	}
	
	static long calc() {
		table = new long[N + 1][K + 1];
		acumTable = new long[N + 1][K + 1];
		for (int n = 0; n <= N; n++) {
			for (int k = 0; k <= K; k++) {
				if (n == 0) {
					table[n][k] = 1;
					acumTable[n][k] = (table[n][k] + (k > 0 ? acumTable[n][k - 1] : 0)) % M;
					continue;
				}
				table[n][k] = 0;
				for (int i = 1; i <= n; i++) {
					long tmp = (comb[n - 1][i - 1] * table[n - i][k]) % M;
					long tmp2 = (acumTable[i - 1][K] + M - acumTable[i - 1][k]) % M;
					table[n][k] += tmp * tmp2;
					table[n][k] %= M;
				}
				acumTable[n][k] = (table[n][k] + (k > 0 ? acumTable[n][k - 1] : 0)) % M;
			}
		}
		return table[N][0];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		N = sc.nextInt();
		K = sc.nextInt();
		M = sc.nextInt();
		calcComb();
		System.out.println(calc());
	}
}