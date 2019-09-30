import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c = sc.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] z = new int[n];
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextInt() - 1;
			y[i] = sc.nextInt() - 1;
			z[i] = sc.nextInt() - 1;
		}
		int[][] imos = new int[40][100010];
		for(int i = 0; i < n; i++) {
			imos[z[i]][x[i]]++;
			imos[z[i]][y[i] + 1]--;
		}
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < 100009; j++) {
				imos[i][j + 1] += imos[i][j];
				if(imos[i][j] >= 2) imos[i][j] = 1;
			}
		}
		int ans = 0;
		for(int i = 0; i < 100010; i++) {
			int cnt = 0;
			for(int j = 0; j < c; j++) {
				cnt += imos[j][i];
			}
			ans = Math.max(ans, cnt);
		}
		System.out.println(ans);
	}
}