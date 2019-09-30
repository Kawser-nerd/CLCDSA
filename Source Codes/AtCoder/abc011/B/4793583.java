import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		scanner.close();

		String formatted = "";

		if (s.length() == 1) {
			formatted = s.toUpperCase();
		} else {
			formatted = s.substring(0, 1).toUpperCase() + s.substring(1, s.length()).toLowerCase();
		}

		System.out.println(formatted);
	}

}