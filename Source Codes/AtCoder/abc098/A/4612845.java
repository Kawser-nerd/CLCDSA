import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int a=stdIn.nextInt();
		int b=stdIn.nextInt();
		int buf=-10000;
		if(buf<a+b)buf=a+b;
		if(buf<a-b)buf=a-b;
		if(buf<a*b)buf=a*b;
		System.out.println(buf);
	}
}