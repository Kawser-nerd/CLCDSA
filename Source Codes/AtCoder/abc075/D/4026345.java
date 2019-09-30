import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		long[] x = new long[N];
		long[] y = new long[N];
		for(int i = 0; i < N; i++) {
			x[i] = sc.nextLong();
			y[i] = sc.nextLong();
		}
		sc.close();
		long ans = Long.MAX_VALUE;
		if(K == 2) {
			for(int i = 0; i < N; i++) {
				for(int j = i + 1; j < N; j++) {
					long x1 = Math.min(x[i], x[j]);
					long x2 = Math.max(x[i], x[j]);
					long y1 = Math.min(y[i], y[j]);
					long y2 = Math.max(y[i], y[j]);
					long s = (x2 - x1) * (y2 - y1);
					ans = Math.min(ans, s);
				}
			}
			System.out.println(ans);
			System.exit(0);
		}
		if(K == 3) {
			for(int i = 0; i < N; i++) {
				for(int j = i + 1; j < N; j++) {
					for(int k = j + 1; k < N; k++) {
						long x1 = Math.min(x[i], Math.min(x[j], x[k]));
						long x2 = Math.max(x[i], Math.max(x[j], x[k]));
						long y1 = Math.min(y[i], Math.min(y[j], y[k]));
						long y2 = Math.max(y[i], Math.max(y[j], y[k]));
						long s = (x2 - x1) * (y2 - y1);
						ans = Math.min(ans, s);
					}
				}
			}
			System.out.println(ans);
			System.exit(0);
		}
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				for(int k = j + 1; k < N; k++) {
					for(int l = k + 1; l < N; l++) {
						long x1 = Math.min(Math.min(x[i], x[j]), Math.min(x[k], x[l]));
						long x2 = Math.max(Math.max(x[i], x[j]), Math.max(x[k], x[l]));
						long y1 = Math.min(Math.min(y[i], y[j]), Math.min(y[k], y[l]));
						long y2 = Math.max(Math.max(y[i], y[j]), Math.max(y[k], y[l]));
						int cnt = 0;
						for(int m = 0; m < N; m++) {
							if(x1 <= x[m] && x[m] <= x2 && y1 <= y[m] && y[m] <= y2) {
								cnt++;
							}
						}
						if(cnt >= K) {
							long s = (x2 - x1) * (y2 - y1);
							ans = Math.min(ans, s);
						}
					}
				}
			}
		}
		System.out.println(ans);
	}
}