import java.util.*;
public class Main {
	public static void main(String[] args){
 
		Scanner sc = new Scanner(System.in);
 
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int D = sc.nextInt();
 
		int train = Math.min(A, B);
		int bus = Math.min(C, D);
 
			System.out.println(train + bus);
	}
}