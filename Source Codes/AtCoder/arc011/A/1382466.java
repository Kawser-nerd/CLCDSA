import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();
		int N = scanner.nextInt();
		int pused = N;
		int result = pused;
		while (pused >= m) {
			int precycle = pused / m;
			pused -= precycle * m;
			pused += precycle * n;
			result += precycle * n;
		}
		System.out.println(result);
	}
}