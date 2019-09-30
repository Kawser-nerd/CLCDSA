import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a,b,c;
		a=sc.nextInt();
		b=sc.nextInt();
		if(a*b%2==0)System.out.println("No");
		else System.out.println("Yes");
	}
}