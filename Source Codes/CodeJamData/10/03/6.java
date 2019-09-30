import static java.lang.System.*;
import java.util.*;

class Main {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(in);
		int tcc = sc.nextInt();
		for(int tc = 1; tc <= tcc; ++tc) {
			int r = sc.nextInt();
			int k = sc.nextInt();
			int n = sc.nextInt();
			int[] arr = new int[n];
			for(int i = 0; i < n; ++i) arr[i] = sc.nextInt();
			long ans = 0;
			long[] score = new long[n];
			int[] vis = new int[n];
			int pos = 0;
			while(r > 0) {
				if(vis != null && score != null) {
					if(vis[pos] != 0) {
						int len = vis[pos] - r;
						long change = ans - score[pos];
						int reps = r / len;
						if(reps > 0) {
							r -= len * reps;
							ans += change * reps;
						}
						vis = null;
						score = null;
						continue;
					}
					score[pos] = ans;
					vis[pos] = r;
				}
				int s = k;
				int g = 0;
				while(s >= arr[pos] && g < n) {
					s -= arr[pos];
					pos = (pos + 1) % n;
					++g;
				}
				ans += k - s;
				--r;
			}
			out.printf("Case #%d: %d%n", tc, ans);
		}
	}
}
