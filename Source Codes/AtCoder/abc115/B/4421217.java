import java.util.Arrays;
import java.util.Scanner;
public class Main {
	static int N;
	int a[]=new int[N];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		int a[]=new int[N];
		for(int i=0;i<N;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		a[N-1]=a[N-1]/2;
		for(int i=1;i<N;i++) {
			a[0]+=a[i];
		}
		System.out.println(a[0]);
	}
}