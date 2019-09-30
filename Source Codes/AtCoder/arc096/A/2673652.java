import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();

		int price = 0;
		price += Math.min(2*C, A+B) * Math.min(X, Y);
		if(X>Y) {
			price += (X-Y)*A;
		}else {
			price += (Y-X)*B;
		}

		int AB = Math.max(X, Y)*2*C;

		System.out.println(Math.min(price, AB));

	}

}