import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int cnt = 0;
		for(int i = a; i <= b; i++) {
			int fi = i / 10000;
			int on = i % 10;
			int fo = i / 1000 % 10;
			int tw = i % 100 / 10 ;  
			if(fi == on && fo == tw) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}
}