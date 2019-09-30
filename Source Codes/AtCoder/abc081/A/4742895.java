import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int yoke = 0;
		int count = 0;
		for(int i = 0;i<3;i++) {
			count += a%10;
			a -= a%10;
			a /= 10;
		}
		System.out.println(count);

	}

}