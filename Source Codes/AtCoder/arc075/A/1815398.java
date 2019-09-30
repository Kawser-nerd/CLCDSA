import java.util.*;
public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = Integer.MAX_VALUE;
		int total = 0;
		for(int i = 1; i<=N; i++) {
			int n = sc.nextInt();
			total += n;
			if(n < M && n%10 != 0) M = n;
		}
		
		if(total % 10 != 0) System.out.println(total);
		else if(M == Integer.MAX_VALUE) System.out.println(0);
		else System.out.println(total-M);
	}

}