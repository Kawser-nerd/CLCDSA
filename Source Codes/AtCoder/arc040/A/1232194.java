import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int t=0,a=0;
		for(int i=s.nextInt();i>0;i--) {
			String st=s.next();
			for(int j=0;j<st.length();j++) {
				if(st.charAt(j)=='R')
					t++;
				if(st.charAt(j)=='B')
					a++;
			}
		}
		System.out.println(t>a?"TAKAHASHI":t<a?"AOKI":"DRAW");
	}
}