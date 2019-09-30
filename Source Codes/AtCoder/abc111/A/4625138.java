import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int a = N/100;
		int b = (N%100)/10;
		int c = N%10;
		int ans = 0;
		if(a == 9) {
			ans+=100;
		}else if(a==1) {
			ans+=900;
		}else {
			ans += 100*a;
		}
		
		if(b == 9) {
			ans+=10;
		}else if(b==1) {
			ans+=90;
		}else {
			ans += 10*b;
		}
		if(c == 9) {
			ans+=1;
		}else if(c==1) {
			ans+=9;
		}else {
			ans += 1*c;
		}
		System.out.println(ans);
	}

}