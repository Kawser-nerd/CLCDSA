import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int m = scanner.nextInt();
			String result = "";
			if (m < 100) {
				result = "00";
			} else if ((m >= 100) && (m <= 5000)) {
				result = String.format("%02d", m * 10 / 1000);
			} else if ((m >= 6000) && (m <= 30000)) {
				result = String.format("%02d", m / 1000 + 50);
			} else if ((m >= 35000) && (m <= 70000)) {
				result = String.format("%02d", (m / 1000 - 30) / 5 + 80);
			} else if (m > 70000) {
				result = "89";
			}
			System.out.println(result);
		}
	}
}