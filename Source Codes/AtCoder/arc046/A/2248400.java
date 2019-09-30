import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int j = sc.nextInt();
		int num = (j-1) % 9 + 1;
		int time = (j+8) / 9;
		for(int i = 0; i < time; i++) {
			System.out.print(num);
		}
		System.out.println();
	}
}