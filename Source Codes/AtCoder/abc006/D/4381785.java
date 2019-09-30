import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int[] maxes = new int[n];
		for (int i = 0; i < n; i++) {
			int max = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] < arr[i]) {
					if (max < maxes[j]) {
						max = maxes[j];
					};
				}
			}
			maxes[i] = max + 1;
		}
		Arrays.sort(maxes);
		System.out.println(n - maxes[n - 1]);
	}
}