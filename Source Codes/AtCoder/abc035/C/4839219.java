import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] cnt = new int[n + 2];
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			cnt[l]++;
			cnt[r + 1]--;
		}
		sc.close();

		for (int i = 1; i < cnt.length; i++) {
			cnt[i] = cnt[i - 1] + cnt[i];
		}

		for (int i = 1; i <= n; i++) {
			System.out.print(cnt[i] % 2 == 1 ? 1 : 0);
		}
		System.out.println();
	}
}