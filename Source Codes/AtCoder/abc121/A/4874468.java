import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int h = sc.nextInt();
		int w = sc.nextInt();
		
		int x = H * W - (h * W + H * w - h * w);
		
		System.out.println(x);
		
	}
}