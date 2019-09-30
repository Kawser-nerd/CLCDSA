import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int shiro = scan.nextInt();
		int green = scan.nextInt();
		int money = scan.nextInt();

		int waruA = money/shiro;
		int waruB = money/green;
		int waruans =0;
		if(waruA > waruB) {
			waruans = waruA;
		}else {
			waruans = waruB;
		}
		System.out.println(waruans);
	}
}