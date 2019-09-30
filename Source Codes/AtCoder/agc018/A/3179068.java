import java.util.Scanner;

public class Main{
	
	public static void main(String args[])throws Exception{

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] a = new int[N];
		for(int i=0;i<N;i++) {
			a[i] = sc.nextInt();
		}
		int GCD = getGCD(a);
		Boolean B = false;
		for(int i=0;i<N;i++) {
			if(a[i]>=K&&(a[i]-K)%GCD==0) {
				B = true;
			}
		}
		if(B) {
			System.out.println("POSSIBLE");
		}else {
			System.out.println("IMPOSSIBLE");
		}
		
		
	}
	
	static int getGCD(int a,int b) {
		if(a<b) {
			int c = a;
			a = b;
			b = c;
		}
		if(a%b==0) {
			return b;
		}else {
			return getGCD(b,a%b);
		}
	}
	static //???????????????????????
	int getGCD(int[] a){
		int gcd = a[0];
		int l = a.length;
		for(int i=1;i<l;i++) {
			gcd = getGCD(gcd,a[i]);
		}
		return gcd;
	}
}