import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String ab = scanner.nextLine();
		scanner.close();

		String[] splited = ab.split(" ");
		String swaped = splited[1] + " " + splited[0];

		System.out.println(swaped);
	}

}