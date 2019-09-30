import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		if(a%b == 0) {
			System.out.println(0);
		}else {
			System.out.println(1);
		}
	}
}