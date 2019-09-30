import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		char x = sc.next().charAt(0);
		System.out.println(x - 'A' + 1);
	}
}