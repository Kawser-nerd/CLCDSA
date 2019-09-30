import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), k = sc.nextInt();
		Integer[] l = new Integer[n];
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt();
		}
		Arrays.sort(l, Collections.reverseOrder());
		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans += l[i];
		}
		System.out.println(ans);
	}
}