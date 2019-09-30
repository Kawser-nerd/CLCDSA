import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long C = sc.nextLong();
		long K = sc.nextLong();
		long[] T = new long[N];
		for(int i = 0; i < N; i++) {
			T[i] = sc.nextLong();
		}
		sc.close();
		Arrays.sort(T);
		int cnt = 1;
		long c = 1;
		long t = T[0] + K;
		for(int i = 1; i < N; i++) {
			if(c < C) {
				if(T[i] <= t) {
					c++;
				}else {
					cnt++;
					c = 1;
					t = T[i] + K;
				}
			}else {
				cnt++;
				c = 1;
				t = T[i] + K;
			}
		}
		System.out.println(cnt);
	}
}