import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(n / 10 * 100 + Math.min(100, n % 10 * 15));
	}
}