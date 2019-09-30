import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		if(a+b==c||b+c==a||a+c==b) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}