import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = 0;
		int[] kind = new int[m];
		for (int i = 0; i < n; i++) {
			k = sc.nextInt();
			for (int j = 0; j < k; j++) {
				kind[sc.nextInt() - 1]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (kind[i] == n)
				ans++;
		}
		System.out.println(ans);
	}
}