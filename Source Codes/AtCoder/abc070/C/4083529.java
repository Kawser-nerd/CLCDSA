import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		long b = sc.nextLong();
		for(int i = 1; i<a; i++){
			long h=sc.nextLong();
			b=(b/gcd(b,h))*h;
		}
		System.out.println(b);
	}
	public static long gcd(long q,long p){
		if(p==0){
			return q;
		}else{
			return gcd(p,q%p);
		}
	}
}