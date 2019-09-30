import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		int a = Integer.parseInt(sc.next());
		int b = a * 2;
		
		double trate = 0;

		System.out.println(b);
		System.out.flush();
		sc.close();
	}
}