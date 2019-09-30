import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
	int n=sc.nextInt();
	int m=sc.nextInt();
	long ans=0;
	String bin = Integer.toBinaryString(m);
	for(int i=0;i!=bin.length()
			;i++) {
				int c=sc.nextInt();
				if(bin.charAt(bin.length()-1-i)=='1') {ans+=c;}
				}
	System.out.println(ans);
	}
}