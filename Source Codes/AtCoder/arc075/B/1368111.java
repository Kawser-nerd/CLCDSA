import java.util.*;

public class Main{ // Main
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		long a = scanner.nextLong();
		long b = scanner.nextLong();
		long[] health = new long[n];
		for(int i = 0; i < n; i ++) {
			health[i] = scanner.nextInt();
		}
		long min = 1;
		long max = (long) Math.pow(10, 9);
		long ans = 0;
		while(min < max) {
			long med = (min + max) / 2;
			long count = 0;
			for(int i = 0; i < n; i ++) {
				long k = (health[i] - med * b + a - b - 1) / (a - b);
				k = Math.max(0, k);
				count += k;
			}
			if(count <= med) {
				ans = med;
				max = med;
			} else {
				min = med + 1;
			}
		}
		System.out.println(ans);
				
		scanner.close();
	}
}