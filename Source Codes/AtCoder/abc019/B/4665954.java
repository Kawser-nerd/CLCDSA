import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		String S="";
		int i=0;
		while(i<s.length()) {
			int l=1;
			for(int j=i+1;j<s.length();j++) {
				if(s.substring(i,i+1).equals(s.substring(j,j+1))) l++;
				else break;
			}
			S+=s.substring(i,i+1)+l;
			i+=l;
		}
		System.out.println(S);
	}
	}