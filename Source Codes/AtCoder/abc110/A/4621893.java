import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int[] a=new int [3];
		a[0]=sc.nextInt();
		a[1]=sc.nextInt();
		a[2]=sc.nextInt();
		int buf1=0;
		int buf2=-1;
		for(int i=0;i<=2;i++) {
			if(a[i]>buf1) {
				buf1=a[i];
				buf2=i;
			}
		}
		a[buf2]*=10;
		int ans=0;
		for(int i:a) {
			ans+=i;
		}
		System.out.println(ans);
	}
}