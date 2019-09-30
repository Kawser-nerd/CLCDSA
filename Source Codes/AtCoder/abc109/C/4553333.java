import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		int X=sc.nextInt();
		int[]x=new int[N+1];
		x[0]=X;
		for(int i=1;i<N+1;i++) {
			x[i]=sc.nextInt();
		}
		Arrays.sort(x);
		int[]dif=new int[N];
		for(int i=0;i<N;i++) {
			dif[i]=x[i+1]-x[i];
		}
		Arrays.sort(dif);
		//System.out.println(Arrays.toString(dif));
		for(int i=0;i<N-1;i++) {
			dif[i+1]=koyaku(dif[i],dif[i+1]);
		}
		//System.out.println(Arrays.toString(dif));
		System.out.println(dif[N-1]);
	}
	static int koyaku(int b,int a) {
		int mod;
		while(true) {
			mod=a%b;
			if(mod==0) {
				return b;
			}
			a=b;
			b=mod;
		}
	}
}