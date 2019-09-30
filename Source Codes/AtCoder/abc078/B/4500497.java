import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int length = sc.nextInt();
		int width = sc.nextInt();
		int space = sc.nextInt();
		int ans = 0;

		ans = (length-space)/(width+space);

		System.out.println(ans);
	}

}