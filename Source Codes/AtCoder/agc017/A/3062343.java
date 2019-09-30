import java.util.Scanner;

public class Main{
	public static void main(String args[])throws Exception{

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int P = sc.nextInt();
		int [] A = new int[N];
		int e = 0;
		int o = 0;
		long pat = 1;
		for(int i=0;i<N;i++) {
			A[i] = sc.nextInt();
			if(A[i]%2 == 0) {
				o++;
			}else {
				e++;
			}
		}
		for(;o>0;o--) {
			pat = pat * 2;
		}
		if(P==0) {
			if(e==0) {
				System.out.println(pat);
			}else {
				for(;e>1;e--) {
					pat = pat * 2;
				}
				System.out.println(pat);
			}
		}else {
			if(e==0) {
				System.out.println(0);
			}else {
				for(;e>1;e--) {
					pat = pat * 2;
				}
				System.out.println(pat);
			}
		}
		
		
			
		
		
	}
}