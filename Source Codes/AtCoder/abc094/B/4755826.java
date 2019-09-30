import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n=sc.nextInt(), m=sc.nextInt(), x=sc.nextInt();
		int[] ar = new int[n+1];
		for (int i=0; i<m; i++) {
			int temp = sc.nextInt();
			ar[temp]++;
		}
		
		int costL=0, costR=0;
		for (int i=x; i>=0; i--) costL += ar[i];
		for (int i=x; i<=n; i++) costR += ar[i];
		
		out.println(Math.min(costL,costR));
	}
}