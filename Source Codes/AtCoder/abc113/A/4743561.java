import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		int x, y, sum;
		Scanner scanner = new Scanner(System.in);

		x = scanner.nextInt();
		y = scanner.nextInt();

		sum = x + (y / 2);

		System.out.println(sum);
	}

}