import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		arr[0] = sc.nextInt();
		for (int i = 1; i < n; i++) {
			arr[i] = arr[i - 1] + sc.nextInt();
		}
		if (arr[n - 1] == 0) {
			System.out.println(0);
			return;
		}
		if (arr[n - 1] % n != 0) {
			System.out.println(-1);
			return;
		}
		int same = arr[n - 1] / n;
		int count = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] % same == 0 && arr[i] / same == i + 1) {
				count++;
			}
		}
		System.out.println(n - 1 - count);
	}
}