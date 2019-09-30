import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int count = 0;
		for(int i = a; i <= b; i ++) {
			int tt = i /10000;
			int fi = i %10;
			int th = i /1000 %10;
			int te = i /10 % 10;
			if(tt == fi && th == te) {
				count++;
			}
		}
		System.out.println(count);
		sc.close();
	}
}