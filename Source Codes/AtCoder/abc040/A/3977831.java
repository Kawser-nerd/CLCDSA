import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=b-a;
		if(c<0) {
			c*=-1;
		}
		if(c<=b-1) {
			System.out.println(c);
		}
		else {
			System.out.println(b-1);
		}
	}
}