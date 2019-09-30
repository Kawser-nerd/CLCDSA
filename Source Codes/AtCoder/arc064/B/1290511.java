import java.util.*;

public class Main {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		char[] c = str.toCharArray();
		boolean tag = false;
		if(c[0]==c[c.length-1]){
			if(c.length%2==0) System.out.println("First");
			else System.out.println("Second");
		}
		else{
			if(c.length%2==0) System.out.println("Second");
			else System.out.println("First");
		}
	}
}