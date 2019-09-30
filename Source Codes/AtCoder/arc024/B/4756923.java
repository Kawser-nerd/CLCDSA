import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int prev = -1;
		int count = 0;
		int max = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (prev == arr[i % n]) {
				count++;
				if (max < count) {
					max = count;
				}
			} else {
				count = 1;
			}
			prev = arr[i % n];
		}
		if (max > n) {
			System.out.println(-1);
		} else {
			System.out.println((max - 1) / 2 + 1);
		}
	}
}