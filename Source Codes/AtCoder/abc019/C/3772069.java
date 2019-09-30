import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int[] a=new int[N];
		for(int i=0; i<N; i++) {
			a[i]=sc.nextInt();
		}
		for(int i=0; i<N; i++) {
			while(a[i]%2==0) {
				a[i]/=2;
			}
		}
		Arrays.sort(a);
		int syurui=1;
		int now=a[0];
		for(int i=1; i<N; i++) {
			if(now!=a[i]) {
				syurui++;
				now=a[i];
			}
		}
		System.out.println(syurui);
	}
}