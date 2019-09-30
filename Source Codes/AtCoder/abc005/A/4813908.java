import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = 0;
		c = b/a; 
		
		System.out.println(c);
		System.out.flush();
		sc.close();
	}
}