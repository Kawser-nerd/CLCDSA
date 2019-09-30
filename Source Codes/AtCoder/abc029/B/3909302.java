import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int ans=0;
		for(int i=0;i!=12;i++) {
			String b=scan.next();
			for(int j=0;j!=b.length();j++) {
				char c=b.charAt(j);
				if(c=='r') {
					ans++;
					break;
				}
			}
		}
		System.out.println(ans);
		
	}
}