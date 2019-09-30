import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int a[] = new int[N + 1];
		long ans = 0;
		int cnt = 1;
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		
		for(int i = 1; i < N; i++) {
			if(a[i] > a[i - 1]) {
				cnt++;
				if(i == N - 1) {
					for(int j = 1; j <= cnt; j++) {
						ans += j;
					}
				}
			} else {
				for(int j = 1; j <= cnt; j++) {
					ans += j;
				}
				cnt = 1;
				if(i == N - 1) ans++;
			}
		}
		System.out.println(ans);
	}
}