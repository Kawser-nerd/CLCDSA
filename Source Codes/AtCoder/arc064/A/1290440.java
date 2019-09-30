import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int x = sc.nextInt();
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		long count = 0;
		int dp[] = new int[N];
		for (int i = 0; i < N; i++) {
			if (arr[i] > x) {
				count += arr[i] - x;
				arr[i] = x;
			}
		}
		for (int i = 1; i < N; i++) {
			if (arr[i] + arr[i - 1] > x) {
				count += arr[i] + arr[i - 1] - x;
				arr[i] = x - arr[i - 1];
			}
		}
		System.out.println(count);

	}
}