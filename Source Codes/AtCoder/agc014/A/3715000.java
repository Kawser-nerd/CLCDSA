import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int sum=a+b+c;

		if(a%2==1 || b%2==1 || c%2==1) {
			System.out.println(0);
		}
		else if(a==b&&b==c) {
			System.out.println(-1);
			System.exit(0);
		}
		else {
			int max=11451419;
			int tmpc=0;
			while(true) {
				long ksn=(((long)sum)*(powz(2,tmpc+1)-powz(-1,tmpc+1))+((long)a)*(3*powz(-1,tmpc+1)))/(3*powz(2,tmpc+1));
				if(ksn%2==0) {
					tmpc++;
				}
				else {
					max=Math.min(max, tmpc);
					tmpc=0;
					break;
				}
			}

			while(true) {
				long ksn=(((long)sum)*(powz(2,tmpc+1)-powz(-1,tmpc+1))+((long)b)*(3*powz(-1,tmpc+1)))/(3*powz(2,tmpc+1));
				if(ksn%2==0) {
					tmpc++;
				}
				else {
					max=Math.min(max, tmpc);
					tmpc=0;
					break;
				}
			}

			while(true) {
				long ksn=(((long)sum)*(powz(2,tmpc+1)-powz(-1,tmpc+1))+((long)c)*(3*powz(-1,tmpc+1)))/(3*powz(2,tmpc+1));
				if(ksn%2==0) {
					tmpc++;
				}
				else {
					max=Math.min(max, tmpc);
					tmpc=0;
					break;
				}
			}
			System.out.println(max+1);
		}
	}
	static long powz(long a,long b) {
		long tmpa=1;
		for(int i=0; i<b; i++) {
			tmpa*=a;
		}
		return tmpa;
	}
}