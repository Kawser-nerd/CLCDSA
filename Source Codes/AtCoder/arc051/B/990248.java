import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sn = new Scanner(System.in);
		int K = sn.nextInt();

		int a = 1,b = 1;
		int tmp = 0;
		for(int i = 0; i < K; ++i){
			tmp = a + b;
			b = a;
			a = tmp;			
		}
		/*
		int c = gcd(a,b,0);
		System.out.println(c);
		*/
		System.out.print(a);
		System.out.print(' ');
		System.out.println(b);
	}
	/*
	public static int gcd(int a,int b,int count){
		if(b == 0) return count;
		count++;
		return gcd(b,a%b,count);
	}
	*/
}