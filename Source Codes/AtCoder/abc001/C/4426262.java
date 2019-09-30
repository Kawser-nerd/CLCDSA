import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		double Deg = sc.nextDouble();
		double Dis = sc.nextDouble();
		double w = Dis / 60.0;
		BigDecimal bd = new BigDecimal(Double.toString(w));
		BigDecimal b = bd.setScale(1, BigDecimal.ROUND_HALF_UP);
		//System.out.println(b);
		int ans = RecuestWindPower(b.doubleValue());
		if(ans != 0) {
			System.out.print(RecuestWindDirection(Deg / 10));
		} else {
			System.out.print("C");
		}
		System.out.print(" ");
		System.out.print(ans);
		System.out.println();
	}
	
	public static int RecuestWindPower(double dis_sec) {
		//System.out.println(dis_sec);
		int w = 0;
		if(dis_sec >= 0.0 && dis_sec <= 0.2) {
			w = 0;
		} else if(dis_sec >= 0.3 && dis_sec <= 1.5) {
			w = 1;
		} else if(dis_sec >= 1.6 && dis_sec <= 3.3) {
			w = 2;
		} else if(dis_sec >= 3.4 && dis_sec <= 5.4) {
			w = 3;
		} else if(dis_sec >= 5.5 && dis_sec <= 7.9) {
			w = 4;
		} else if(dis_sec >= 8.0 && dis_sec <= 10.7) {
			w = 5;
		} else if(dis_sec >= 10.8 && dis_sec <= 13.8) {
			w = 6;
		} else if(dis_sec >= 13.9 && dis_sec <= 17.1) {
			w = 7;
		} else if(dis_sec >= 17.2 && dis_sec <= 20.7) {
			w = 8;
		} else if(dis_sec >= 20.8 && dis_sec <= 24.4) {
			w = 9;
		} else if(dis_sec >= 24.5 && dis_sec <= 28.4) {
			w = 10;
		} else if(dis_sec >= 28.5 && dis_sec <= 32.6) {
			w = 11;
		} else if(dis_sec >= 32.7) {
			w = 12;
		}
		return w;
	}
	
	public static String RecuestWindDirection(double deg) {
		String str = "";
		if(deg < 11.25) {
			str = "N";
		}else if(deg < 33.75) {
			str = "NNE";
		} else if(deg < 56.25) {
			str = "NE";
		} else if(deg < 78.75) {
			str = "ENE";
		} else if(deg < 101.25) {
			str = "E";
		} else if(deg < 123.75) {
			str = "ESE";
		} else if(deg < 146.25) {
			str = "SE";
		} else if(deg < 168.75) {
			str = "SSE";
		} else if(deg < 191.25) {
			str = "S";
		} else if(deg < 213.75) {
			str = "SSW";
		} else if(deg < 236.25) {
			str = "SW";
		} else if(deg < 258.75) {
			str = "WSW";
		} else if(deg < 281.25) {
			str = "W";
		} else if(deg < 303.75) {
			str = "WNW";
		} else if(deg < 326.25) {
			str = "NW";
		} else if(deg < 348.75) {
			str = "NNW";
		} else {
			str = "N";
		}
		return str;
	}
}