import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String range = scanner.nextLine();
		scanner.close();

		int delimiterPos = range.indexOf(" ");
		int s = Integer.parseInt(range.substring(0, delimiterPos));
		int t = Integer.parseInt(range.substring(delimiterPos + 1));

		int num = t - (s - 1);

		System.out.println(num);
	}

}