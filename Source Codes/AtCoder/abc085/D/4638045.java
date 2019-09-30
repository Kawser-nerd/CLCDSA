import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		long h = sc.nextLong();
		long[] b = new long[n];
		long max=0;
		for(int i = 0; i<n; i++){
			long a = sc.nextLong();
			long b1 = sc.nextLong();
			b[i]=b1;
			max=Math.max(max,a);
		}
		long ans=0;
		int count=n-1;
		Arrays.sort(b);
		while(h>0){
			if(count>=0 && b[count]>max){
				h-=b[count];
				count--;
			}else{
				h-=max;
			}
			ans++;
		}
		System.out.println(ans);
	}
}