import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int ans = (w - 1) * h + (h - 1) * w;
		System.out.println(ans);
	}
}