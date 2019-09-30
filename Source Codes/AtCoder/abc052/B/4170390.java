import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		String b=scan.next();
		int ans=0;
		int count=0;
		for(int i=0;i!=a;i++) {
		if(b.charAt(i)=='I') {
			count++;
		}
		else {
			count--;
		}
		if(count>ans) {
			ans=count;
		}
		}
		System.out.println(ans);
	}
}