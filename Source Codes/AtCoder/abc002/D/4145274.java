import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int x[] = new int[M];
		int y[] = new int[M];

		boolean xy[][] = new boolean[N][N];
		for (int i = 0; i < M; i++) {
			x[i] = sc.nextInt()-1;
			y[i] = sc.nextInt()-1;
			xy[x[i]][y[i]] = xy[y[i]][x[i]] = true;
		}

		int ans = 1;

		for (int i = 0; i < Math.pow(2,N); i++) {
			int cnt = 0;
			Set<Integer> set = new HashSet<>();
			for (int j = 0; j < N; j++) {
				if ((1&i>>j) == 1) {
					set.add(j);
				}
			}
			cnt = set.size();
			for (int a: set) {
				for (int b: set) {
					if (b == a) {
						continue;
					}
					if (!xy[a][b]) {
						cnt =0;
						continue;
					}
				}
			}

			ans = Math.max(ans,cnt);
		}
		System.out.println(ans);
	}
}