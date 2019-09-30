import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = "";
		for(int i = 0 ; i < (n - 1) / 9 + 1 ; i++) {
			s += String.valueOf((n - 1) % 9 + 1);
		}
		System.out.println(s);
	}
}