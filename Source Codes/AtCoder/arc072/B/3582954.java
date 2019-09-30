import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long x = in.nextLong(), y = in.nextLong();
		System.out.println(Math.abs(x - y) <= 1 ? "Brown" : "Alice");
	}
}