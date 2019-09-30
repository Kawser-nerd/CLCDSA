import java.util.Scanner;
public class Main {
	static int N,M;
	static String ans="-1 -1 -1";
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		for(int b=0;b<=1;b++) { //??(3)
			for(int a=0;a<=N-b;a++){//??(2)
				if(a*2+b*3+(N-a-b)*4==M) ans=a+" "+b+" "+(N-a-b);
			}
		}
		System.out.println(ans);
	}
}