import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String dir = new String[] {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"}[((sc.nextInt() * 10 + 1125) / 2250) % 16];
		int[] power = new int[] {2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326, Integer.MAX_VALUE};
		int speed = Double.valueOf(Math.round(sc.nextInt() / 6D)).intValue();
		for(int i = 0; i <= power.length; i++) {
			if(speed > power[i])
				continue;

			System.out.println((i == 0 ? "C" : dir) + " " + i);
			break;
		}
	}

}