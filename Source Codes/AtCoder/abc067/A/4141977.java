import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		if(a%3==0||b%3==0||(a+b)%3==0)
		{
			System.out.println("Possible");
		}
		else {
			System.out.println("Impossible");
		}
	}
}