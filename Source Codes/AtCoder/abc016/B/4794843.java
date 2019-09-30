import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String[] abc = scanner.nextLine().split(" ");
		scanner.close();

		int a = Integer.parseInt(abc[0]);
		int b = Integer.parseInt(abc[1]);
		int c = Integer.parseInt(abc[2]);

		boolean isPlus = a + b == c;
		boolean isMinus = a - b == c;

		String ret = "";
		if (isPlus && isMinus) {
			ret = "?";
		} else if (isPlus) {
			ret = "+";
		} else if (isMinus) {
			ret = "-";
		} else {
			ret = "!";
		}

		System.out.println(ret);
	}

}