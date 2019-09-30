import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int nn = sc.nextInt();
		int sum = nn;
		int remain = nn;
		int next = remain / m * n;
		while (next > 0) {
			remain %= m;
			sum += next;
			remain += next;
			next = remain / m * n;
		}
		System.out.println(sum);
	}
}