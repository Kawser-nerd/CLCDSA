import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		int[] time = new int[num];
		for (int i = 0; i < time.length; i++) {
			time[i] = scanner.nextInt();
		}
		scanner.close();

		int min = time[0];
		for (int t : time) {
			if (t < min) {
				min = t;
			}
		}

		System.out.println(min);
	}

}