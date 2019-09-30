import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int n2 = n;
		int s = 0;
		
		while(0 < n) {
			s += n % 10;
			n = n / 10;
		}
		
		if(n2 % s == 0) {
			System.out.print("Yes");
		}
		else {
			System.out.print("No");
		}
		
		
	}

}