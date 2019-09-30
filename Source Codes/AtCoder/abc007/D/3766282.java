import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Long sa=sc.nextLong();
		String s=(sa-1)+"";
		String t=sc.next();
		String S8="";
		String T8="";
		int[] ary= {0,1,2,3,3,4,5,6,7,7};
		boolean s849=false;
		boolean t849=false;

		for(int i=0; i<s.length(); i++) {
			if(!s849) {
				if(s.charAt(i)-48==4 || s.charAt(i)-48==9) {
					s849=true;
					S8=S8+ary[s.charAt(i)-49]+"";
				}
				else {
					S8=S8+ary[s.charAt(i)-48]+"";
				}
			}
			else {
				S8=S8+"7";
			}

		}
		for(int i=0; i<t.length(); i++) {
			if(!t849) {
				if(t.charAt(i)-48==4 || t.charAt(i)-48==9) {
					t849=true;
					T8=T8+ary[t.charAt(i)-49]+"";
				}
				else {
					T8=T8+ary[t.charAt(i)-48]+"";
				}
			}
			else {
				T8=T8+"7";
			}
		}
		//System.out.println(S8+" "+T8);
		long decS8=Long.parseLong(S8, 8);
		long decT8=Long.parseLong(T8, 8);
		long rawT8=Long.parseLong(t);
		System.out.println((long)((rawT8-sa+1)-(decT8-decS8)));
	}
}