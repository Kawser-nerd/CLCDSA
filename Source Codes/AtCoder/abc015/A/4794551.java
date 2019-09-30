import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String a = scanner.nextLine();
		String b = scanner.nextLine();
		scanner.close();

		String longer = a;
		if (b.length() > a.length()) {
			longer = b;
		}

		System.out.println(longer);
	}

}