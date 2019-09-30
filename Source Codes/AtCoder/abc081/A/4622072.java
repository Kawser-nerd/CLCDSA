import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			String string = scanner.nextLine();
			System.out.println(string.chars().filter(x -> x == '1').count());
		}
	}
}