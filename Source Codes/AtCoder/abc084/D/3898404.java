import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int Q = sc.nextInt();
		int l[] = new int[Q];
		int r[] = new int[Q];
		for(int i = 0; i< Q; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}
		
		int prime_cnt[] = new int[100001];
		boolean prime[] = new boolean[100001];
		Arrays.fill(prime, true);
		prime[0] = false;
		prime[1] = false;
		int cnt = 0;
		for(int i = 2; i <= 100000; i++) {
			int c = 2;
			while(i * c <= 100000) {
				prime[i * c] = false;
				c++;
			}
		}
		
		
		for(int i = 3; i <= 100000; i++) {
			if(!prime[(i + 1) / 2] || !prime[i]) {
				prime_cnt[i] = cnt;
				continue;
			}
			cnt++;
			prime_cnt[i] = cnt;
		}
		
		for(int i = 0; i < Q; i++) {
			System.out.println(prime_cnt[r[i]] - prime_cnt[l[i] - 1]);
		}
	}
}