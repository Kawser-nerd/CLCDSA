import java.util.*;
import java.math.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int dig = sc.nextInt() * 10;
		BigDecimal dis = new BigDecimal(sc.next()).divide(new BigDecimal("60"), 1, BigDecimal.ROUND_HALF_UP);
		String dir = "";
		if (dig >= 1125 && dig < 3375) {
			dir = "NNE";
		} else if (dig >= 3375 && dig < 5625) {
			dir = "NE";
		} else if (dig >= 5625 && dig < 7875) {
			dir = "ENE";
		} else if (dig >= 7875 && dig < 10125) {
			dir = "E";
		} else if (dig >= 10125 && dig < 12375) {
			dir = "ESE";
		} else if (dig >= 12375 && dig < 14625) {
			dir = "SE";
		} else if (dig >= 14625 && dig < 16875) {
			dir = "SSE";
		} else if (dig >= 16875 && dig < 19125) {
			dir = "S";
		} else if (dig >= 19125 && dig < 21375) {
			dir = "SSW";
		} else if (dig >= 21375 && dig < 23625) {
			dir = "SW";
		} else if (dig >= 23625 && dig < 25875) {
			dir = "WSW";
		} else if (dig >= 25875 && dig < 28125) {
			dir = "W";
		} else if (dig >= 28125 && dig < 30375) {
			dir = "WNW";
		} else if (dig >= 30375 && dig < 32625) {
			dir = "NW";
		} else if (dig >= 32625 && dig < 34875) {
			dir = "NNW";
		} else {
			dir = "N";
		}
		int w = 0;
		if (new BigDecimal("32.7").compareTo(dis) <= 0) {
			w = 12;
		} else if (new BigDecimal("28.5").compareTo(dis) <= 0) {
			w = 11;
		} else if (new BigDecimal("24.5").compareTo(dis) <= 0) {
			w = 10;
		} else if (new BigDecimal("20.8").compareTo(dis) <= 0) {
			w = 9;
		} else if (new BigDecimal("17.2").compareTo(dis) <= 0) {
			w = 8;
		} else if (new BigDecimal("13.9").compareTo(dis) <= 0) {
			w = 7;
		} else if (new BigDecimal("10.8").compareTo(dis) <= 0) {
			w = 6;
		} else if (new BigDecimal("8.0").compareTo(dis) <= 0) {
			w = 5;
		} else if (new BigDecimal("5.5").compareTo(dis) <= 0) {
			w = 4;
		} else if (new BigDecimal("3.4").compareTo(dis) <= 0) {
			w = 3;
		} else if (new BigDecimal("1.6").compareTo(dis) <= 0) {
			w = 2;
		} else if (new BigDecimal("0.3").compareTo(dis) <= 0) {
			w = 1;
		} else if (new BigDecimal("0.0").compareTo(dis) <= 0) {
			w = 0;
		}
		if (w == 0) {
			dir = "C";
		}
		System.out.println(dir + " " + w);
	}
}