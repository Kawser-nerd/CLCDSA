import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		char c = sc.next().charAt(0);
		System.out.println(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? "vowel" : "consonant");
	}
}