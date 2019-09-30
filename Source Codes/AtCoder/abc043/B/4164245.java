import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String a=scan.next();
		int count=0;
		int ans[]=new int[a.length()];
		Arrays.fill(ans,-1);
		for(int i=0;i!=a.length();i++) {
			char b=a.charAt(i);
			if(b=='0') {
				ans[count]=0;
				count++;
			}if(b=='1') {
				ans[count]=1;
				count++;
			}
			if(b=='B'){
				count--;
				if(count<0) {
					count=0;
				}
				ans[count]=-1;
			}
			if(count<0) {
				count=0;
			}
		}
		for(int i=0;i!=a.length();i++) {
			if(ans[i]==-1) {
				break;
			}
			System.out.print(ans[i]);
		}
		System.out.println();
		
	}
	}