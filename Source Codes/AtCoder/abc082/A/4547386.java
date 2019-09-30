import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner sc = new Scanner(System.in);
		double a = sc.nextInt();
		double b = sc.nextInt();
		double x = 0;

		if((a + b) % 2 == 0)
			x = (a + b) / 2;
		else
			x = ((a + b) / 2) + 1;

		System.out.println((int)x);

		sc.close();
	}

}