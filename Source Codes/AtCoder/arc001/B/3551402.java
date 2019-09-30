import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// ?????
		int A = sc.nextInt();
		int B = sc.nextInt();
		int a = 0;
		int b = 0;
		
		a = Math.min(A, B);
		b = Math.max(A, B);
		
		b=b-a;
		
		int cnt = 0;
		
		while(b!=0) {
			
			if(Math.abs(b-10)<=2||b-10>=0) {
				b=Math.abs(b-10);
				cnt++;
				continue;
			}else if(Math.abs(b-5)<=2||b-5>=0) {
				b=Math.abs(b-5);
				cnt++;
				continue;
			}else {
				b=Math.abs(b-1);
				cnt++;
				continue;
			}
			
		}
		
		System.out.println(cnt);
		
	}

}