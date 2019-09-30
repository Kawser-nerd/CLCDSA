import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		String a = sc.next();
//		int b = Integer.parseInt(sc.next());
		String c = null;
		if(a.contains("9")){
			c = "Yes";
		}else{
			c = "No";
		}
		System.out.println(c);
		System.out.flush();
		sc.close();
	}
}