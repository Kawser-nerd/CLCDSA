import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int[] array = new int[3] ;
		array[0] = sc.nextInt();
		array[1] = sc.nextInt();
		array[2] = sc.nextInt();
		Arrays.sort(array);

		System.out.println(array[0] * array[1] / 2);

	}
}