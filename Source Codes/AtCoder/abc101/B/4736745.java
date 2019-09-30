///Good words cool more than cold water.
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();

		int b = a;
		int sum = 0;
		while(b > 0) {
			sum += b%10;
			b -= b%10;
			b /= 10;
		}
		if(a%sum == 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}