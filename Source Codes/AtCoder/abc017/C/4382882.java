import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		long[] jwels = new long[m];
		long total = 0;
		for (int i = 0; i < n; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			int s = sc.nextInt();
			jwels[l - 1] += s;
			if (r - 1 < m - 1) {
				jwels[r] -= s;
			}
			total += s;
		}
		for (int i = 1; i < m; i++) {
			jwels[i] += jwels[i - 1];
		}
      
		Arrays.sort(jwels);
		System.out.println(total - jwels[0]);
	}
}