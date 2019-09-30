import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		long[] a = new long[N];
		long[] b = new long[N];
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			if(a[i] >= 0) {
				b[i] = a[i];
			}
		}
		sc.close();
		long[] c = new long[N + 1];
		long[] d = new long[N + 1];
		for(int i = 0; i < N; i++) {
			c[i + 1] = c[i] + a[i];
			d[i + 1] = d[i] + b[i];
		}
		long max = Long.MIN_VALUE;
		for(int i = 0; i <= N - K; i++) {
			if(i == 0) {
				max = d[N] - d[K];
				if(c[K] > 0) {
					max += c[K];
				}
			}else {
				long t = d[i] + d[N] - d[K + i];
				if(c[K + i] - c[i] > 0) {
					t += c[K + i] - c[i];
				}
				max = Math.max(max, t);
			}
		}
		System.out.println(max);
	}
}