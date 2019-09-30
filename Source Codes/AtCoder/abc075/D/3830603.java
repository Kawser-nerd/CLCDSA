import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		long x[] = new long[N];
		long y[] = new long[N];
		for(int i = 0; i < N; i++) {
			x[i] = sc.nextLong();
			y[i] = sc.nextLong();
		}
		
		long ans = Long.MAX_VALUE;
		for(int left = 0; left < N; left++) {
			for(int right = 0; right < N; right++) {
				for(int up = 0; up < N; up++) {
					for(int down = 0; down < N; down++) {
						int cnt = 0;
						for(int i = 0; i < N; i++) {
							if(x[left] <= x[i] && x[i] <= x[right] && y[i] <= y[up] && y[down] <= y[i]) {
								cnt++;
							}
						}
						if(cnt >= K) {
							ans = Math.min(ans, Math.abs(x[left] - x[right]) * Math.abs(y[up] - y[down]));
						}
					}
				}
			}
		}
		System.out.println(ans);
	}
}