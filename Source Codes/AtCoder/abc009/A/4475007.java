import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		double box = scn.nextDouble();
		int ans = 0;

		double a =box/2;
		ans = (int)Math.ceil(a);

		System.out.println(ans);

	}

}