import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		sc.close();

		int[] cnt = new int[1000002];
		for (int i = 0; i < n; i++) {
			cnt[a[i]]++;
			cnt[b[i] + 1]--;
		}
		for (int i = 1; i <= 1000000; i++) {
			cnt[i] = cnt[i - 1] + cnt[i];
		}

		int ans = 0;
		for (int i = 0; i <= 1000000; i++) {
			ans = Math.max(ans, cnt[i]);
		}
		System.out.println(ans);
	}
}