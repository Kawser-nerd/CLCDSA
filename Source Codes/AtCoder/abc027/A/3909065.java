import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		if(a==b) {
			System.out.println(c);
		}
		else if(a==c) {
			System.out.println(b);
		}
		else if(b==c) {
			System.out.println(a);
		}
	}
}