import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		System.out.println(
				s.nextLine()
				.replaceAll("Left", "<")
				.replaceAll("Right", ">")
				.replaceAll("AtCoder", "A")
				);
	}
}