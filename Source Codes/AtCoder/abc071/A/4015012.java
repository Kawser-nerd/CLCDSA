import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		if(Math.abs(a-b)>Math.abs(a-c)) {
			System.out.println("B");
		}
		else {
			System.out.println("A");
		}
	}
}