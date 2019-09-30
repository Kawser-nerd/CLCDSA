import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		String s3 = sc.next();

		System.out.println("" + s1.toUpperCase().charAt(0)
							+ s2.toUpperCase().charAt(0)
							+ s3.toUpperCase().charAt(0));

		sc.close();


	}
}