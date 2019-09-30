import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a=sc.nextInt(), b=sc.nextInt(), c=sc.nextInt(), k=sc.nextInt();
		int total = a+b+c;
		int max = max(a,b,c);
		int pow = (int)Math.pow(2,k);
		out.println((total-max)+max*pow);
	}
	
	static int max(int... ar) {
		Arrays.sort(ar);
		return ar[ar.length-1];
	}
}