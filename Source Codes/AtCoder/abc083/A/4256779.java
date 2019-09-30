import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
		System.out.println(a + b > c + d ? "Left" : a + b == c + d ? "Balanced" : "Right");
		sc.close();
	}

}