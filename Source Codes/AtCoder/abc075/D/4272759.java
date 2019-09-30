import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int K = Integer.parseInt(sc.next());
		int[][] z = new int[N][2];
		int[] x = new int[N];
		int[] y = new int[N];
		for (int i = 0; i < N; i++) {
			z[i][0] = Integer.parseInt(sc.next());
			z[i][1] = Integer.parseInt(sc.next());
			x[i] = z[i][0];
			y[i] = z[i][1];
		}
		Arrays.sort(x);
		Arrays.sort(y);
		long ans = Long.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = k + 1; l < N; l++) {
						int count = 0;
						int left = x[i];
						int right = x[j];
						int down = y[k];
						int up = y[l];
						for (int c = 0; c < N; c++) {
							if (left <= z[c][0] && z[c][0] <= right && down <= z[c][1] && z[c][1] <= up)
								count++;
						}
						if (count >= K)
							ans = Math.min(ans, (long)(right - left) * (up - down));
					}
				}
			}
		}
		System.out.println(ans);
	}
}