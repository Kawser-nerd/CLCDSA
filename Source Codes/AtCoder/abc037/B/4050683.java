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
			int t = sc.nextInt();
			for (int j = l - 1; j < r; j++) {
				arr[j] = t;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(arr[i]).append("\n");
		}
		System.out.print(sb);
	}
}