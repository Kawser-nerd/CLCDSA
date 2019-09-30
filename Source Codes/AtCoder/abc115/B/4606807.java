import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int max = sc.nextInt();
		int P = max;
		int b;
		for(int i=0;i<N-1;i++) {
			b = sc.nextInt();
			if(b>max) {
				max =b;
			}
			P+=b;
		}
		max = max/2;
		P = P-max;
       System.out.println(P);		
	}
}