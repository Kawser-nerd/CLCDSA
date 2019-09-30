import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N2 = sc.nextInt() * 2;
		int[] L = new int[N2];
		for (int i = 0; i < N2; i++) {
			L[i] = sc.nextInt();
		}
		Arrays.sort(L);
		int ans = 0;
		for (int i = 0; i < N2; i+=2) {
			ans += L[i];
		}
		System.out.println(ans);
	}
}