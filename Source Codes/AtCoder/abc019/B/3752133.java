import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String res="";
		int tmp=0;
		int kaisu=0;
		tmp=a.charAt(0);
		kaisu=1;
		for(int i=1; i<a.length(); i++) {
			if(tmp==a.charAt(i)) {
				kaisu++;
			}
			else {
				res=res+((char)tmp)+""+kaisu+"";
				tmp=a.charAt(i);
				kaisu=1;
			}
		}
		res=res+((char)tmp)+""+kaisu+"";
		System.out.println(res);
	}
}