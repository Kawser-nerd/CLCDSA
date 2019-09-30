import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		String a = sc.next();
//		int b = Integer.parseInt(sc.next());
		String boin = "[aeoiu]";
		a = a.replaceAll(boin, "");
		System.out.println(a);
		System.out.flush();
		sc.close();
	}
}