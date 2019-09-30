import java.util.*;
import java.util.Comparator;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		long x[] = new long[N];
		long y[] = new long[N];
		long z[] = new long[N];
		long all_plus[] = new long[N];
		long all_minus[] = new long[N];
		long beautiful_plus[] = new long[N];
		long beautiful_minus[] = new long[N];
		long delicious_plus[] = new long[N];
		long delicious_minus[] = new long[N];
		long popular_plus[] = new long[N];
		long popular_minus[] = new long[N];
		for(int i = 0 ; i < N; i++) {
			x[i] = sc.nextLong();
			y[i] = sc.nextLong();
			z[i] = sc.nextLong();
			all_plus[i] = x[i] + y[i] + z[i];
			all_minus[i] = -x[i] - y[i] - z[i];
			beautiful_plus[i] = x[i] - y[i] - z[i];
			beautiful_minus[i] = -x[i] + y[i] + z[i];
			delicious_plus[i] = -x[i] + y[i] - z[i];
			delicious_minus[i] = x[i] - y[i] + z[i];
			popular_plus[i] = -x[i] - y[i] + z[i];
			popular_minus[i] = x[i] + y[i] + -z[i];
		}
		
		Arrays.sort(all_plus);
		Arrays.sort(all_minus);
		Arrays.sort(beautiful_plus);
		Arrays.sort(beautiful_minus);
		Arrays.sort(delicious_plus);
		Arrays.sort(delicious_minus);
		Arrays.sort(popular_plus);
		Arrays.sort(popular_minus);
		long all_p = 0;
		long all_m = 0;
		long beautiful_p = 0;
		long beautiful_m = 0;
		long delicious_p = 0;
		long delicious_m = 0;
		long popular_p = 0;
		long popular_m = 0;
		for(int i = N - 1; i > N - 1 - M; i--) {
			all_p += all_plus[i];
			all_m += all_minus[i];
			beautiful_p += beautiful_plus[i];
			beautiful_m += beautiful_minus[i];
			delicious_p += delicious_plus[i];
			delicious_m += delicious_minus[i];
			popular_p += popular_plus[i];
			popular_m += popular_minus[i];
		}
		
		System.out.println(Math.max(all_p, Math.max(all_m, Math.max(beautiful_p, Math.max(beautiful_m, Math.max(delicious_p, Math.max(delicious_m, Math.max(popular_p, popular_m))))))));
	}
}