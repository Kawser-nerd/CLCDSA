import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int deg = scanner.nextInt();
			String mdis = scanner.nextLine().trim();
			BigDecimal sdis = new BigDecimal(mdis).divide(new BigDecimal(60), 1, RoundingMode.HALF_UP);
			String dir = "";
			if ((112.5 < deg) && (deg < 337.5)) {
				dir = "NNE";
			} else if ((337.5 < deg) && (deg < 562.5)) {
				dir = "NE";
			} else if ((562.5 < deg) && (deg < 787.5)) {
				dir = "ENE";
			} else if ((787.5 < deg) && (deg < 1012.5)) {
				dir = "E";
			} else if ((1012.5 < deg) && (deg < 1237.5)) {
				dir = "ESE";
			} else if ((1237.5 < deg) && (deg < 1462.5)) {
				dir = "SE";
			} else if ((1462.5 < deg) && (deg < 1687.5)) {
				dir = "SSE";
			} else if ((1687.5 < deg) && (deg < 1912.5)) {
				dir = "S";
			} else if ((1912.5 < deg) && (deg < 2137.5)) {
				dir = "SSW";
			} else if ((2137.5 < deg) && (deg < 2362.5)) {
				dir = "SW";
			} else if ((2362.5 < deg) && (deg < 2587.5)) {
				dir = "WSW";
			} else if ((2587.5 < deg) && (deg < 2812.5)) {
				dir = "W";
			} else if ((2812.5 < deg) && (deg < 3037.5)) {
				dir = "WNW";
			} else if ((3037.5 < deg) && (deg < 3262.5)) {
				dir = "NW";
			} else if ((3262.5 < deg) && (deg < 3487.5)) {
				dir = "NNW";
			} else {
				dir = "N";
			}
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