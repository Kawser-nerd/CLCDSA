import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		int d=Math.abs(a+b-c);
		int e=Math.abs(b-a-c);
		if(c>=b&&c<=b+a||c+a>=b&&c+a<=b+a) {
			System.out.println(0);
		}
		else {
			System.out.println(d<=e?d:e);
		}
		}
	}