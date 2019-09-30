import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

	private static final String[] DIRS = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW",
			"W", "WNW", "NW", "NNW", "N" };

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int deg = scanner.nextInt();
			String mdis = scanner.nextLine().trim();
			BigDecimal sdis = new BigDecimal(mdis).divide(new BigDecimal(60), 1, RoundingMode.HALF_UP);
			int index = (int) ((deg + 112.5) / 225.0);
			String dir = DIRS[index];

			String w = "";
			if ((sdis.compareTo(new BigDecimal("0.0")) >= 0) && (sdis.compareTo(new BigDecimal("0.2")) <= 0)) {
				w = "0";
				dir = "C";
			} else if ((sdis.compareTo(new BigDecimal("0.3")) >= 0) && (sdis.compareTo(new BigDecimal("1.5")) <= 0)) {
				w = "1";
			} else if ((sdis.compareTo(new BigDecimal("1.6")) >= 0) && (sdis.compareTo(new BigDecimal("3.3")) <= 0)) {
				w = "2";
			} else if ((sdis.compareTo(new BigDecimal("3.4")) >= 0) && (sdis.compareTo(new BigDecimal("5.4")) <= 0)) {
				w = "3";
			} else if ((sdis.compareTo(new BigDecimal("5.5")) >= 0) && (sdis.compareTo(new BigDecimal("7.9")) <= 0)) {
				w = "4";
			} else if ((sdis.compareTo(new BigDecimal("8.0")) >= 0) && (sdis.compareTo(new BigDecimal("10.7")) <= 0)) {
				w = "5";
			} else if ((sdis.compareTo(new BigDecimal("10.8")) >= 0) && (sdis.compareTo(new BigDecimal("13.8")) <= 0)) {
				w = "6";
			} else if ((sdis.compareTo(new BigDecimal("13.9")) >= 0) && (sdis.compareTo(new BigDecimal("17.1")) <= 0)) {
				w = "7";
			} else if ((sdis.compareTo(new BigDecimal("17.2")) >= 0) && (sdis.compareTo(new BigDecimal("20.7")) <= 0)) {
				w = "8";
			} else if ((sdis.compareTo(new BigDecimal("20.8")) >= 0) && (sdis.compareTo(new BigDecimal("24.4")) <= 0)) {
				w = "9";
			} else if ((sdis.compareTo(new BigDecimal("24.5")) >= 0) && (sdis.compareTo(new BigDecimal("28.4")) <= 0)) {
				w = "10";
			} else if ((sdis.compareTo(new BigDecimal("28.5")) >= 0) && (sdis.compareTo(new BigDecimal("32.6")) <= 0)) {
				w = "11";
			} else if ((sdis.compareTo(new BigDecimal("32.7")) >= 0)) {
				w = "12";
			}
			System.out.println(dir + " " + w);
		}
	}
}