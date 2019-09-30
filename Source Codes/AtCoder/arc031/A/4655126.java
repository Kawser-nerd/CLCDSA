import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String name = sc.next();
		String names[] = name.split("");
		String ans = "";


		if(name.length()%2==0) {
			String a = name.substring(0,name.length()/2);
			String b = name.substring((name.length()/2),name.length());
			String[] aa = a.split("");
			String[] bb = b.split("");
			for(int i=0; i<a.length(); i++) {
				if(!aa[i].equals(bb[b.length()-(i+1)])) {
					ans = "NO";
				}
				else {
					ans = "YES";
				}
			}
		}else {
			int j = name.length()-1;
			int l = (j/2);
			String c = name.substring(0,l);
			String d = name.substring(l+1,name.length());
			String[] cc = c.split("");
			String[] dd = d.split("");
			for(int k =0; k<l; k++) {
				if(!cc[k].equals(dd[d.length()-(k+1)])) {
					ans = "NO";
				}else {
					ans = "YES";
				}
			}
		}
		System.out.println(ans);
	}

}