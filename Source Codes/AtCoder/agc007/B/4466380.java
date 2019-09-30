import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		long[] a=new long[n];
		long[] b = new long[n];
		int[] p=new int[n];
		a[0]=1;
		b[n-1]=1;
		for(int i =0; i<n; i++){
			int p1 = sc.nextInt()-1;
			p[i]=p1;
			if(i>0){
				a[i]=a[i-1]+20000;
				b[n-1-i]=b[n-i]+20000;
			}
		}
		for(int i=0; i<n; i++){
			a[p[i]]+=i;
		}
		for(int i =0; i<n; i++){
			System.out.print(a[i]+" ");
		}
		System.out.println();
		for(int i =0; i<n; i++){
			System.out.print(b[i]+" ");
		}
	}
}