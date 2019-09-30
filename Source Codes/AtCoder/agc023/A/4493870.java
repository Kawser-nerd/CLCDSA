import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
		}
		sc.close();
		long[] b = new long[N + 1];
		for(int i = 0; i < N; i++) {
			b[i + 1] = b[i] + A[i];
		}
		Map<Long, Long> m = new TreeMap<Long, Long>();
		for(int i = 1; i <= N; i++) {
			m.merge(b[i], 1l, (v1, v2) -> (v1 + v2));
		}
		long ans = 0;
//		for(long k : m.keySet()) {
//			System.out.printf("%d %d\n", k, m.get(k));
//		}
		for(long k : m.keySet()) {
			if(k == 0) {
				long t = m.get(k);
				ans += t * (t + 1) / 2;
			}else {
				long t = m.get(k);
				ans += t * (t - 1) / 2;
			}
		}
		System.out.println(ans);
	}
}