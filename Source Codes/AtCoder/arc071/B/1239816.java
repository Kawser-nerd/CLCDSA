import java.util.Arrays;
import java.util.Scanner;
public class Main{
		public static void main(String[] args){
		long PRIME=1000000007;
		Scanner sc=new Scanner(System.in);
		int N =Integer.parseInt(sc.next());
		int M =Integer.parseInt(sc.next());
		long[] x= new long[N];
		long[] y= new long[M];
		for(int i=0;i<N;i++)x[i]=Long.parseLong(sc.next());
		for(int j=0;j<M;j++)y[j]=Long.parseLong(sc.next());
		Arrays.sort(x);
		Arrays.sort(y);
		long xans =0;
		long yans =0;
		for(int i=0;i<N;i++){
			xans=(xans+(i-(N-1-i))*x[i])%PRIME;
		}
		for(int j=0;j<M;j++){
			yans=(yans+(j-(M-1-j))*y[j])%PRIME;
		}
		System.out.println((xans*yans)%PRIME);
		sc.close();
	}
}