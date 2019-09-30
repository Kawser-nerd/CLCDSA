import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		long[] x = new long[3];
		for (int i = 0; i < 3; i++) {
			x[i] = sc.nextInt();
		}
		if (x[0] % 2 == 0 || x[1] % 2 == 0 || x[2] % 2 == 0) {
			System.out.println(0);
		} else {
			Arrays.sort(x);
			System.out.println(x[0] * x[1]);
		}
	}
}