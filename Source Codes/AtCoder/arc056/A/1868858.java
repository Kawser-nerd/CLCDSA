import java.util.Scanner;
class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){return Integer.parseInt(s.next());};
	public static void main(String[]$){
		long a=gInt(),b=gInt(),k=gInt(),l=gInt();
		System.out.println(Math.min(k/l*b+(k-k/l*l)*a,(k/l+1)*b));
	}
}