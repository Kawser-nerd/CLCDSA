import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		long ans = 0;
		for(int i = n-1; i >= 0; i-=2) {
			ans += arr[i];
		}
		System.out.println(ans);
	}
}