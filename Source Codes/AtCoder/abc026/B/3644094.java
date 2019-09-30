import java.util.Arrays;
import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] en=new int[n];
		for(int i=0; i<n; i++) {
			en[i]=sc.nextInt();
		}
		Arrays.sort(en);
		long souwa=0;
		int cnt=1;
		for(int i=n-1; i>=0; i--) {
			souwa=souwa+cnt*en[i]*en[i];
			cnt*=-1;
		}
		System.out.println(souwa*3.1415926535);
	}
}