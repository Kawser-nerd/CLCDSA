import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] phrases = {scanner.next(), scanner.next(), scanner.next()};

		Arrays.sort(phrases);
		if(("5".equals(phrases[0]) && "5".equals(phrases[1]))
									&& "7".equals(phrases[2])) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}