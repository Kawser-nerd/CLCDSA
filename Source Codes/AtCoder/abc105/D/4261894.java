import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long M = sc.nextLong();
		long[] A = new long[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
		}
		sc.close();
		long[] b = new long[N + 1];
		b[0] = 0;
		for(int i = 0; i < N; i++) {
			b[i + 1] += b[i] + A[i];
			b[i + 1] %= M;
		}
		Map<Long, Long> map = new HashMap<Long, Long>();
		for(int i = 0; i <= N; i++) {
			map.merge(b[i], 1l, (v1, v2) -> v1 + v2);
		}
		long ans = 0;
		for(long k : map.keySet()) {
			long t = map.get(k);
			ans += t * (t - 1) / 2;
		}
		System.out.println(ans);
	}
}