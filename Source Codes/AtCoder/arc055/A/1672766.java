import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = "1";
		for(int i = 0 ; i < n - 1 ; i++) {
			s += "0";
		}
		s += "7";
		System.out.println(s);
	}
}