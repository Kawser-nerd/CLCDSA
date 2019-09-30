import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			arr[l - 1]++;
			if (r <= n - 1) {
				arr[r]--;
			}
		}
		StringBuilder sb = new StringBuilder();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			sb.append(sum % 2);
		}
		System.out.println(sb);
	}
}