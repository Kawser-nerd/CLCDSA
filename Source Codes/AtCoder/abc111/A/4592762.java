import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int a;
		int sum =0;
		if(N/100==1) {
			a = N-100;
			sum+=900;
			if(a/10==1) {
				a = a-10;
				sum+=90;
				if(a/1==1) {
					sum+=9;
				}
				else if(a/9==1) {
					sum+=1;
				}
			}
			else if(a/10==9) {
				a = a-90;
				sum+=10;
				if(a/1==1) {
					sum+=9;
				}
				else if(a/1==9) {
					sum+=1;			
				}
			}
		}
		if(N/100==9) {
			a = N-900;
			sum+=100;
			if(a/10==1) {
				a = a-10;
				sum+=90;
				if(a/1==1) {
					sum+=9;
				}
				else if(a/9==1) {
					sum+=1;
				}
			}
			else if(a/10==9) {
				a = a-90;
				sum+=10;
				if(a/1==1) {
					sum+=9;
				}
				else if(a/1==9) {
					sum+=1;				
				}
			}
		}
		System.out.println(sum);
	}
}