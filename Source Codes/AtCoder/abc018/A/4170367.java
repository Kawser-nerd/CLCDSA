import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int[][] a = new int[3][3];
		for (int i = 0; i < 3; i++) {
			a[i][0] = i + 1;
			a[i][1] = sc.nextInt();
		}
		Arrays.sort(a, (x, y) -> Integer.compare(y[1], x[1]));
		for (int i = 0; i < 3; i++) {
			a[i][2] = i + 1;
		}
		Arrays.sort(a, Comparator.comparingInt(x -> x[0]));
		for (int i = 0; i < 3; i++) {
			System.out.println(a[i][2]);
		}
	}
}