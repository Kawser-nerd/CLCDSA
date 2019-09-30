import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int h= x/3600;
		x = x%3600;
		int m = x/60;
		x=x%60;
		int s = x;
		
		System.out.printf("%02d:%02d:%02d",h,m,s);
		System.out.println();
	}
}