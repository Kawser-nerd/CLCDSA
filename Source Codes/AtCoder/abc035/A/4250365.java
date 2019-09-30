import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int w = sc.nextInt(), h = sc.nextInt();
		if (w / 4 == h / 3) {
			System.out.println("4:3");
		} else {
			System.out.println("16:9");
		}
	}
}