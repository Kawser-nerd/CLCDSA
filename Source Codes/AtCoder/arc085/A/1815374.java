import java.util.*;
public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(), M = sc.nextInt();
		int x = 1900*M + 100*(N-M);
		System.out.println((int)(x*Math.pow(2, M)));
	}

}