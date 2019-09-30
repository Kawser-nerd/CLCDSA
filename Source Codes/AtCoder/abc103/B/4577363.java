import java.util.Scanner;
 
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String s1 = sc.nextLine();
		String s2 = sc.nextLine();
		String s3;
		int n = s1.length();
		int ans = 0;
		while(n !=0) {
			s3  = switchs(s1,n);
//			System.out.println(s3);
			if(s3.equals(s2)) {
				ans = 1;
				break;
			}
			n--;
		}
		if(ans==1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
	private static String switchs(String s1, int n) {
		return s1.substring(n)+s1.substring(0, n);
	}	
}