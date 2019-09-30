import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		int d=scan.nextInt();
		int e=scan.nextInt();
		int f=scan.nextInt();
		if(e+f>=d) {
			System.out.println(e*a+f*b-c*(e+f));
		}
		else {
			System.out.println(e*a+f*b);
		}
	}
}