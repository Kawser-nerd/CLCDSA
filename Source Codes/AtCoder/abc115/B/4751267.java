import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int max = 0;
		int total = 0;
		
		for(int i = 0 ; i < N ; i++) {
			int p = sc.nextInt();
			total += p;
			if(max<p) {
				max = p;
			}
		}
		
		System.out.println(total - max + max / 2);
	}
}