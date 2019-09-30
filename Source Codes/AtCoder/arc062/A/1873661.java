import java.util.Scanner;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){return Integer.parseInt(s.next());}

	public static void main(String[]$){
		int n=gInt();
		long a=gInt(),b=gInt();

		for(int i=1;i<n;++i) {
			int A=gInt(),B=gInt();
			if(a*1.0/A<b*1.0/B) {
				b=(b+B-1)/B*B;
				a=b/B*A;
			}else {
				a=(a+A-1)/A*A;
				b=a/A*B;
			}
		}
		System.out.println(a+b);
	}
}