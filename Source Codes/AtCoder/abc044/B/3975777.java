import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

		String w = scan.next();
		while (w.length() % 2 == 0 && w.length() != 0) {
			w = w.replace(String.valueOf(w.charAt(0)), "");
		}
		if (w.length() == 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}