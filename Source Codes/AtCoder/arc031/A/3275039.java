import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String b="";
		StringBuffer sb = new StringBuffer(a);
		b=sb.reverse().toString();
		if(a.equals(b)) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}