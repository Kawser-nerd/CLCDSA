import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int cnt=0;
		Scanner in =new Scanner(System.in);
		int n=in.nextInt();
		String str=new String("Takahashikun");
		String sss =new String("Takahashikun.");
		str=str.toUpperCase();
		sss=sss.toUpperCase();
		for(int i=1;i<=n;i++) {
			String s=in.next();
			s=s.toUpperCase();
			if(s.equals(str)==true||s.equals(sss)==true)cnt++;
		}
		System.out.println(cnt);
	}

}