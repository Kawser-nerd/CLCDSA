import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int mennseki = (a*b) - (a*1) - (b*1) + (1*1);
		System.out.println(mennseki);
	}

}