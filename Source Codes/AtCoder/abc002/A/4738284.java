import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		long x = scanner.nextInt();
		long y = scanner.nextInt();
		scanner.close();

	    long max = Math.max(x, y);

		System.out.println(max);
	}

}