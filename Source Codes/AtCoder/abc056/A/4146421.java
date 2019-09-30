import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();

		if (a.equals("H")) {
			if (b.equals("H")) {
				System.out.println("H");
			} else {
				System.out.println("D");
			}
		} else {
			if (b.equals("H")) {
				System.out.println("D");
			} else {
				System.out.println("H");
			}
		}

		sc.close();


	}
}