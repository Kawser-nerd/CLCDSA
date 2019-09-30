import java.util.Scanner;

public class Main {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int avg = (sc.nextInt() + sc.nextInt()  + 2 - 1) / 2;
		System.out.print(avg);
	}

}