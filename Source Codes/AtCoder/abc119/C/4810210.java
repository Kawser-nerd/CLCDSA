import static java.lang.Math.*;

import java.util.Scanner;


public class Main {
	static int N,A,B,C;
	static int[] take;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		 N = sc.nextInt();
		 A = sc.nextInt();
		 B = sc.nextInt();
		 C = sc.nextInt();
		 take = new int[N];
;
		for(int i = 0 ; i < N ; i++){
			take[i] = sc.nextInt();
		}

		sc.close();

		System.out.println(calmp(0,0,0,0));
	}

		static int calmp(int n, int a , int b, int c){
			if(n == N){
				return (min(min(a,b),c) > 0 ) ? (abs(A-a)+abs(B-b)+abs(C-c)-30) : 30000;
			}
			int mp0 = calmp(n+1, a, b, c);
			//System.out.println("mp0 : "+mp0);

			int mp1 = calmp(n+1, a+take[n], b, c) + 10;
			//System.out.println("mp1 : "+mp1);

			int mp2 = calmp(n+1, a, b+take[n], c) + 10;
			//System.out.println("mp2 : "+mp2);

			int mp3 = calmp(n+1, a, b, c+take[n]) + 10;
			//System.out.println("mp3 : "+mp3);

			return min(min(mp0, mp1),min(mp2, mp3));
		}
	}