import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// standard input
		String s = sc.next();

		// process
		boolean isStrLenEvenNumber = (s.length() % 2 == 0);
		boolean isSameFirstAndLast = (s.charAt(0) == (s.charAt(s.length() - 1)));

		// standard output
		System.out.println((isStrLenEvenNumber && isSameFirstAndLast) || (!isStrLenEvenNumber && !isSameFirstAndLast)? 
				"First": "Second");
	}
}