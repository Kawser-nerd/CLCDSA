import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int q=sc.nextInt();
		long[] a1=new long[a+2];
		long[] b1=new long[b+2];
		a1[0]=b1[0]=Long.MIN_VALUE;
		a1[a+1]=b1[b+1]=Long.MAX_VALUE/2;
		long[] ans1=new long[q];
		for(int i = 1; i<=a; i++){
			a1[i]=sc.nextLong();
		}
		for(int i = 1; i<=b; i++){
			b1[i]=sc.nextLong();
		}
		for(int k = 0; k<q; k++){
			long x=sc.nextLong();
			long ans=Long.MAX_VALUE;
			int idxa=-Arrays.binarySearch(a1,x)-1;
			int[] a2={idxa,(idxa==1)? a+1:idxa-1};
			int idxb=-Arrays.binarySearch(b1,x)-1;
			int[] b2={idxb,(idxb==1)? b+1:idxb-1};
			for(int i:a2){
				for(int j:b2){
					ans=Math.min(ans,Math.abs(a1[i]-x)+Math.abs(a1[i]-b1[j]));
					ans=Math.min(ans,Math.abs(b1[j]-x)+Math.abs(a1[i]-b1[j]));
				}
			}
			ans1[k]=ans;
		}
		for(int i = 0; i<q; i++){
			System.out.println(ans1[i]);
		}
	}
}