import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			double metre = Double.parseDouble(scan.nextLine());
			double vv = vv(metre);
			if (vv < 10)
				System.out.println("0" + (int) vv);
			else
				System.out.println("" + (int) vv);
		}
	}

	public static double vv(double metre) {
		double km = metre / 1_000;
		if (km < 0.1)
			return 0;
		else if (km <= 5)
			return km * 10;
		else if (km <= 30)
			return km + 50;
		else if (km <= 70)
			return (km - 30) / 5 + 80;
		else
			return 89;
	}
}