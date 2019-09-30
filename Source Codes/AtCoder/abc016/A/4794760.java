import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String[] md = scanner.nextLine().split(" ");
		scanner.close();

		int m = Integer.parseInt(md[0]);
		int d = Integer.parseInt(md[1]);
		
		String ret = "NO";
		if (m % d == 0) {
			ret = "YES";
		}

		System.out.println(ret);
	}

}