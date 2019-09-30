import java.util.Scanner;
public class Main {
	static int N,NG1,NG2,NG3;
	static String ans="NO";
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		NG1=sc.nextInt();
		NG2=sc.nextInt();
		NG3=sc.nextInt();
		if(N==NG1||N==NG2||N==NG3)N=400;
		for(int j=0;j<100;j++) {
		for(int i=3;i>0;i--) {
		  if(N-i!=NG1&&N-i!=NG2&&N-i!=NG3) {
			  N-=i;
			 i=0;
		  }
		}
		}
		if(N<1)ans="YES";
		System.out.println(ans);
	}
}