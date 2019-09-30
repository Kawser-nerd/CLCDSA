import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in) ;

	int w = sc.nextInt();
	int a = sc.nextInt();
	int b = sc.nextInt();

	System.out.println(Math.abs(a - b) <= w ? 0 : Math.abs(a - b) - w);

	sc.close();
	}

}