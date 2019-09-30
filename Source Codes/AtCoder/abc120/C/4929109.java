import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// ?????
		String S=sc.next();
		int a=0;
		int b=0;
		for (int i = 0; i < S.length(); i++) {
			if (S.startsWith("1",i)) {
				a++;
			}
			else {
				b++;
			}
		}
	    System.out.println(2*Math.min(a, b));
	  }
}