import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String w = scanner.nextLine();
		scanner.close();

		w = w.replace("a", "").replace("i", "").replace("u", "").replace("e", "").replace("o", "");

		System.out.println(w);
	}

}