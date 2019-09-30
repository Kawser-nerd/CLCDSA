import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		long n[]=new long[3],t;
		int i,j;
		for(i=0;i<3;i++) n[i]=stdIn.nextLong();
		for(i=0;i<2;i++) {
			for(j=2;j>i;j--) {
				if(n[j-1]>n[j]) {
					t=n[j-1];
					n[j-1]=n[j];
					n[j]=t;
				}
			}
		}
		System.out.print(n[0]*n[1]*((n[2]+1)/2)-n[0]*n[1]*(n[2]/2));
	}
}