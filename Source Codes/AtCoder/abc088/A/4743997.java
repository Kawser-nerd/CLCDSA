import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		if(a%500 <= b) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}