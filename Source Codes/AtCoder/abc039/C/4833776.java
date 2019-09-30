import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		sc.close();

		if (s[4] == 'W' && s[5] == 'W' && s[11] == 'W' && s[12] == 'W') {
			System.out.println("Do");

		} else if (s[2] == 'W' && s[3] == 'W' && s[9] == 'W' && s[10] == 'W') {
			System.out.println("Re");

		} else if (s[0] == 'W' && s[1] == 'W' && s[7] == 'W' && s[8] == 'W') {
			System.out.println("Mi");

		} else if (s[6] == 'W' && s[7] == 'W' && s[11] == 'W' && s[12] == 'W') {
			System.out.println("Fa");

		} else if (s[4] == 'W' && s[5] == 'W' && s[9] == 'W' && s[10] == 'W') {
			System.out.println("So");

		} else if (s[2] == 'W' && s[3] == 'W' && s[7] == 'W' && s[8] == 'W') {
			System.out.println("La");

		} else if (s[0] == 'W' && s[1] == 'W' && s[5] == 'W' && s[6] == 'W') {
			System.out.println("Si");
		}
	}
}