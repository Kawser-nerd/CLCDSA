import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] letters = {"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S",
		                    "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
		int[] huuryoku = {0, 15, 93, 201, 327, 477, 645, 831, 1029, 1245, 1467, 1707, 1959};
		int d = sc.nextInt();
		int w = sc.nextInt();
		int wp = 0;
		for (int i = 0; i < huuryoku.length; i++){
			if (huuryoku[i] <= w) wp = i;
		}
		if (wp == 0) System.out.println("C 0");
		else System.out.println(letters[((10 * d + 1125) / 2250 + 15) % 16] + " " + wp);
	}
}