import java.time.Month;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int x = sc.nextInt(), y = sc.nextInt();
		System.out.println(Month.of(x).minLength() == Month.of(y).minLength() ? "Yes" : "No");
	}
}