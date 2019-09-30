import java.util.*;

public class Main {
	static final long MOD = 1000000007L;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int nprev = sc.nextInt();
		int prev = sc.nextInt();
		for (int i = 2; i < n; i++) {
			int t = sc.nextInt();
			if (nprev + prev + t < k) {
				System.out.println(i + 1);
				return;
			}
			nprev = prev;
			prev = t;
		}
		System.out.println(-1);
	}
}