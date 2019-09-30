import java.util.*;

class Main {
	static int[] l;
	static int N,A,B,C;
	static int min=2000000000;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		l = new int[N];
		for (int i=0;i<N;i++) {
			l[i]=sc.nextInt();
		}
		sc.close();
		f(0,0,0,0,0);
		System.out.println(min);
	}
	static void f(int n,int a,int b,int c,int cost) {
		if (n==N) {
			if (a==0 || b==0 || c==0) {
				return;
			}else {
				cost += Math.abs(A-a)+Math.abs(B-b)+Math.abs(C-c)-30;
				min = Math.min(min,cost);
				return;
			}
		}

		f(n+1,a,b,c,cost);
		f(n+1,a+l[n],b,c,cost+10);
		f(n+1,a,b+l[n],c,cost+10);
		f(n+1,a,b,c+l[n],cost+10);
	}
}