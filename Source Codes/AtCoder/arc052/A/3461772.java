import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String S=sc.next();
		int[] sj=new int[2];
		int c=0;

		for(int i=0; i<S.length(); i++) {
			if(S.charAt(i)<=57 && S.charAt(i)>=48) {
				sj[c]=S.charAt(i)-48;
				c++;
			}
		}
		if(c==1) {
			System.out.println(sj[0]);
		}
		else if(c==2) {
			System.out.println(sj[0]*10+sj[1]);
		}
	}
}