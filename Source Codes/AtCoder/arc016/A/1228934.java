import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),m=s.nextInt();
		System.out.println(m%n+1);
	}
}