import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int stat=0;
		for(int i=0; i<s.length(); i++) {
			if(stat==0) {
				if(s.charAt(i)=='I' || s.charAt(i)=='i') {
					stat++;
				}
			}
			else if(stat==1) {
				if(s.charAt(i)=='C' || s.charAt(i)=='c') {
					stat++;
				}
			}
			else if(stat==2) {
				if(s.charAt(i)=='T' || s.charAt(i)=='t') {
					stat++;
				}
			}
		}
		if(stat==3) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}