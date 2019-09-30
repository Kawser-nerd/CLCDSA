import java.util.Scanner;

public class Main {
	static long []p;
	static long []l;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long X = sc.nextLong();
		sc.close();
		p = new long[N + 1];
		l = new long[N + 1];
		p[0] = 1;
		l[0] = 1;
		for(int i = 1; i <= N; i++) {
			p[i] = 2 * p[i - 1] + 1;
			l[i] = 2 * l[i - 1] + 3;
		}
		long ans = rec(N, X);
		System.out.println(ans);
	}
	static long rec(int n, long x) {
		if(n == 0) {
			return 1;
		}
		if(x <= 1) {
			return 0;
		}else if(x < l[n - 1] + 1) {
			return rec(n - 1, x - 1);
		}else if(x == l[n - 1] + 1) {
			return p[n - 1];
		}else if(x == l[n - 1] + 2){
			return p[n - 1] + 1;
		}else if(x < l[n]){
			return rec(n - 1, x - (l[n - 1] + 2)) + p[n - 1] + 1;
		}else {
			return 2 * p[n - 1] + 1;
		}
	}
}