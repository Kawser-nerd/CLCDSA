import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int souwa=0;

		souwa+=N/10;
		if(N%10>=1) {
			souwa++;
		}
		souwa+=N/100*10;
		if(N%100>=10) {
			souwa+=Math.min(N%100-9, 10);
		}
		souwa+=N/1000*100;
		if(N%1000>=100) {
			souwa+=Math.min(N%1000-99, 100);
		}
		souwa+=N/10000*1000;
		if(N%10000>=1000) {
			souwa+=Math.min(N%10000-999, 1000);
		}
		souwa+=N/100000*10000;
		if(N%100000>=10000) {
			souwa+=Math.min(N%100000-9999, 10000);
		}
		souwa+=N/1000000*100000;
		if(N%1000000>=100000) {
			souwa+=Math.min(N%1000000-99999, 100000);
		}
		souwa+=N/10000000*1000000;
		if(N%10000000>=1000000) {
			souwa+=Math.min(N%10000000-999999, 1000000);
		}
		souwa+=N/100000000*10000000;
		if(N%100000000>=10000000) {
			souwa+=Math.min(N%100000000-9999999, 10000000);
		}
		souwa+=N/1000000000*100000000;
		if(N%1000000000>=100000000) {
			souwa+=Math.min(N%1000000000-99999999, 100000000);
		}
		if(N==1000000000) {
			souwa++;
		}
		System.out.println(souwa);
	}
}