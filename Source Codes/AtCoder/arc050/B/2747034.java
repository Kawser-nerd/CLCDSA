import java.util.Scanner;

class Main{
	static long R;
	static long B;
	static long aka_hon;
	static long ao_hon;
	static long dekiru_max;
	static long min;
	static boolean dekiru;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		dekiru=false;
		R=sc.nextLong();
		B=sc.nextLong();
		aka_hon=sc.nextLong();
		ao_hon=sc.nextLong();
		dekiru_max=Math.max(R, B);
		min=0;
		long mid=(min+dekiru_max)/2;

		while(dekiru_max>1+min) {
			dekiru=false;
			mid=(min+dekiru_max)/2;
			dekiru=Solve(R,B,aka_hon,ao_hon,mid);
			if(dekiru==true) {
				min=mid;
			}
			else if(dekiru==false) {
				dekiru_max=mid;
			}
		}
		System.out.println((min+dekiru_max)/2);
	}

	static boolean Solve(long a,long b,long c,long d,long wa) {		//c akahon  d aohon
		long aka=a-wa;
		long ao=b-wa;
		long po=aka/(c-1)+ao/(d-1);
		return aka>=0&&ao>=0&&po>=wa;
	}
}