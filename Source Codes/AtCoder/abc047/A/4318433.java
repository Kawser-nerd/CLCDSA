import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int[] a = new int[3];
		for (int i = 0; i < 3; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		System.out.println(a[0] + a[1] == a[2] ? "Yes" : "No");
	}
}