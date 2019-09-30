import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static int maxSize;
	
	static boolean ok(int val) {
		return 0 <= val && val < maxSize;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int N = sc.nextInt();
		if (N == 1) {
			System.out.println(1);
			return;
		}
		maxSize = 2 * N - 1;
		char[][] table = new char[2*N-1][2*N-1];
		for (int i = 0; i < N; i++) {
			char[] chars = sc.next().toCharArray();
			for (int j = 0; j < N; j++) {
				table[i][j] = chars[j];
			}
		}
		for (int i = 0; i < table.length; i++) {
			for (int j = 0; j < table.length; j++) {
				table[i][j] = table[i%N][j%N];
			}
		}
		int complete = (N * N - N) / 2;
		int ans = 0;
		int[][] cant = new int[2*N-1][2*N-1];
		for (int delta = -N + 1; delta <= N - 1 ; delta++) {
			for (int i = 0; i < cant.length; i++) {
				Arrays.fill(cant[i], 0);
			}
			for (int dist = 1; dist < N; dist++) {
				for (int i = 0; i < 2 * N; i++) {
					int val = i + delta + dist;
					if (!ok(val) || !ok(i + dist) || !ok(i+delta)) continue;
					if (table[i][val] == table[i+dist][i+delta]) cant[i][val]=1;
					cant[i][val] += cant[i][val-1] + cant[i+1][val]-cant[i+1][val-1];
					if (dist == N - 1 && cant[i][val] == complete) ans++;
				}
			}
		}
		System.out.println(ans);
	}
}