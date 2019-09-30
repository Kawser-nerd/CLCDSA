import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int numH1 = 0;
		int numH2 = 0;

		try {
			scanner = new Scanner(System.in);
			numH1 = scanner.nextInt();
			numH2 = scanner.nextInt();

			System.out.println(numH1 - numH2);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numM = 0;

		try {
			scanner = new Scanner(System.in);
			numM = scanner.nextInt();
			int vv = 0;
			if (numM < 100) {
				vv = 0;
			} else if (numM <= 5000) {
				vv = numM / 100;
			} else if (numM <= 30000) {
				vv = numM / 1000 + 50;
			} else if (numM <= 70000) {
				vv = (numM / 1000 - 30) / 5 + 80;
			} else {
				vv = 89;
			}
			System.out.printf("%02d%n", vv);
			;
		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		try (Scanner sc = new Scanner(System.in);) {

			double Deg = sc.nextDouble();
			double Dis = sc.nextDouble();
			double w = Dis / 60.0;
			BigDecimal bd = new BigDecimal(Double.toString(w)).setScale(1, BigDecimal.ROUND_HALF_UP);
			int ans = getPower(bd.doubleValue());
			if (ans != 0) {
				System.out.print(getAngle(Deg / 10));
			} else {
				System.out.print("C");
			}
			System.out.print(" ");
			System.out.print(ans);
			System.out.println();
		}

	}

	public static int getPower(double power) {
		//System.out.println(dis_sec);
		int w = 0;
		if (power >= 0.0 && power <= 0.2) {
			w = 0;
		} else if (power >= 0.3 && power <= 1.5) {
			w = 1;
		} else if (power >= 1.6 && power <= 3.3) {
			w = 2;
		} else if (power >= 3.4 && power <= 5.4) {
			w = 3;
		} else if (power >= 5.5 && power <= 7.9) {
			w = 4;
		} else if (power >= 8.0 && power <= 10.7) {
			w = 5;
		} else if (power >= 10.8 && power <= 13.8) {
			w = 6;
		} else if (power >= 13.9 && power <= 17.1) {
			w = 7;
		} else if (power >= 17.2 && power <= 20.7) {
			w = 8;
		} else if (power >= 20.8 && power <= 24.4) {
			w = 9;
		} else if (power >= 24.5 && power <= 28.4) {
			w = 10;
		} else if (power >= 28.5 && power <= 32.6) {
			w = 11;
		} else if (power >= 32.7) {
			w = 12;
		}
		return w;
	}

	public static String getAngle(double angle) {
		String str = "";
		if (angle < 11.25) {
			str = "N";
		} else if (angle < 33.75) {
			str = "NNE";
		} else if (angle < 56.25) {
			str = "NE";
		} else if (angle < 78.75) {
			str = "ENE";
		} else if (angle < 101.25) {
			str = "E";
		} else if (angle < 123.75) {
			str = "ESE";
		} else if (angle < 146.25) {
			str = "SE";
		} else if (angle < 168.75) {
			str = "SSE";
		} else if (angle < 191.25) {
			str = "S";
		} else if (angle < 213.75) {
			str = "SSW";
		} else if (angle < 236.25) {
			str = "SW";
		} else if (angle < 258.75) {
			str = "WSW";
		} else if (angle < 281.25) {
			str = "W";
		} else if (angle < 303.75) {
			str = "WNW";
		} else if (angle < 326.25) {
			str = "NW";
		} else if (angle < 348.75) {
			str = "NNW";
		} else {
			str = "N";
		}
		return str;
	}

	private void solveD() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}