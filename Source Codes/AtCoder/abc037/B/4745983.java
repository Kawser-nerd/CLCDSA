import java.util.Scanner;
 
class Main{
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		int n=stdIn.nextInt(),q=stdIn.nextInt(),l,r,t,i,j,a[]=new int[100];
		for(i=0;i<q;i++) {
			l=stdIn.nextInt();
			r=stdIn.nextInt();
			t=stdIn.nextInt();
			for(j=l-1;j<r;j++) a[j]=t;
		}
		for(i=0;i<n;i++) System.out.println(a[i]);
	}
}