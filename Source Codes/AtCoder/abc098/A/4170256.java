import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int max = Integer.MIN_VALUE;
		if ((a + b) > max) {
			max = a + b;
		}
		if ((a - b) > max) {
			max = a - b;
		}
		if ((a * b) > max) {
			max = a * b;
		}
		
		System.out.println(max);
	}
	
}