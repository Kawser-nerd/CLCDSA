import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] q=new int[m];
		int sum = 0;
		for(int i = 0; i < n; i++){
			 int a = sc.nextInt()-1;
			 int b = sc.nextInt();
			 int c = sc.nextInt();
			if(b!=m){
				q[b]-=c;
			}
			q[a]+=c;
			sum+=c;
		}
		for(int i=0;i <m-1; i++){
			q[i+1]+=q[i];
		}
		Arrays.sort(q);
		System.out.println(sum-q[0]);
	}
}