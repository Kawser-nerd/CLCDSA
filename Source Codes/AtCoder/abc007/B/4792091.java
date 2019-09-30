import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String a = scanner.nextLine();
		scanner.close();

		String smaller = "-1";
		if (a.length() != 1) {
			smaller = a.substring(0, a.length() - 1);
		} else {
			if (!a.equals("a")) {
				ArrayList<String> alphabets = new ArrayList<String>();
				int alphaSize = 'z' - 'a';
				char alpha = 'a';
				for (int i = 0; i <= alphaSize; i++) {
					alphabets.add(String.valueOf(alpha));
					alpha++;
				}

				int index = alphabets.indexOf(a) - 1;
				smaller = alphabets.get(index);
			}
		}

		System.out.println(smaller);
	}

}