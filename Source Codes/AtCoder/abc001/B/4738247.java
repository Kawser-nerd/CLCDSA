import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		scanner.close();

	    double mm = m / 1000.0;
		int vvd = 0;

		if (mm < 0.1) {
			vvd = 0;
		} else if (mm >= 0.1 && mm <= 5) {
			vvd = (int)(mm * 10);
		} else if (mm >= 6 && mm <= 30) {
			vvd = (int)(mm + 50);
		} else if (mm >= 35 && mm <= 70) {
			vvd = (int)((mm - 30) / 5 + 80);
		} else if (mm > 70) {
			vvd = 89;
		}

		String vv = String.format("%02d", vvd);

		System.out.println(vv);
	}

}