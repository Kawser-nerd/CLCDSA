import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int s[] = new int[N];
		for(int i = 0; i < N; i++) {
			s[i] = sc.nextInt();
			if(s[i] == 0) {
				System.out.println(N);
				return;
			}
		}
		
		if(K == 0) {
			System.out.println(0);
			return;
		}
		
		long ans = 1;
		int plus_cnt = 0;
		int minus_cnt = 0;
		long max = 0;
		int res = 0;
		while(plus_cnt != N){
			ans *= s[plus_cnt];
			plus_cnt++;
			while(ans > K) {
				ans /= s[minus_cnt];
				minus_cnt++;
			}
			if(max <= ans) {
				if(res < plus_cnt - minus_cnt) {
					res = plus_cnt - minus_cnt;
				}
			}
			//System.out.println(ans);
		}
		System.out.println(res);
	}
}