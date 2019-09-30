import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();

		int hour = n / 3600;
		int minute = (n - hour*3600) / 60;
		int second = (n - hour*3600 - minute*60);

		String formatted = String.format("%02d", hour) + ":" + String.format("%02d", minute) + ":" + String.format("%02d", second);

		System.out.println(formatted);
	}

}