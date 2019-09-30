import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		long[] a1=new long[n];
		for(int i = 0; i<n; i++){
			long a = sc.nextLong();
			a1[i]=a;
		}
		Arrays.sort(a1);
		long ans=1;
		for(int i=0; i<n-1; i++){
			if(a1[i]*2>=a1[i+1]){
				ans++;
			}else{
				ans=1;
			}
			a1[i+1]+=a1[i];
		}
		System.out.println(ans);
	}
}