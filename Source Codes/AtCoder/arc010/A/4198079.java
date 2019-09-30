import java.util.*;
 
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int now = n;
		for (int i = 0; i < m; i++) {
			if (now <= a) {
				now += b;
			}
			int c = sc.nextInt();
			now -= c;
			if (now < 0) {
				System.out.println(i + 1);
				return;
			}
		}
		System.out.println("complete");
	}
}