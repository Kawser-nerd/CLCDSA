import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();

		double salary = 0;
		for (int i = 1; i <= n; i++) {
			salary += i * 10000 * (1.0 / n);
		}
		int salaryInt = (int)salary;

		System.out.println(salaryInt);
	}

}