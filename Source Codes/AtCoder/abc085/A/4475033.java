import java.util.Scanner;

public class Main {

	private static Scanner sc;

	public static void main(String[] args) {

		sc = new Scanner(System.in);
		String dateStr = sc.next();

		System.out.println(dateStr.replaceAll("2017", "2018"));
	}

}