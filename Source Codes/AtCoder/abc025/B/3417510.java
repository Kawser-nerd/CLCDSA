import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int a=scanner.nextInt();
		int b=scanner.nextInt();
		String s[]=new String[n];
		int d[]=new int[n];
		for(int i=0;i<n;i++) {
			s[i]=scanner.next();
			d[i]=scanner.nextInt();
		}
		int p=0;
		String di="";
		for(int i=0;i<n;i++) {
			p+=go(s[i],d[i],a,b);
		}
		if(p<0) {
			p*=-1;
			di="West";
		}else if(p>0){
			di="East";
		}else {
			System.out.println(p);
			return;
		}
		System.out.println(di+" "+p);
		
	}

	private static int go(String s, int d, int a, int b) {
		int n=0;
		if(d<a) {
			n=a;
		}else if(d<=b) {
			n=d;
		}else {
			n=b;
		}
		if(s.equals("West")) {
			n*=-1;
		}
		return n;
	}
}