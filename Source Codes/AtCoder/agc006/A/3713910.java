import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		String s=sc.next();
		String t=sc.next();
		String tmp="";
		int ngs=11451419;
		tmp=s.substring(0,s.length())+t.substring(0,t.length());
		if(tmp.substring(0,N).equals(s) && tmp.substring(tmp.length()-N,tmp.length()).equals(t)) {
			ngs=Math.min(tmp.length(), ngs);
		}
		for(int i=1; i<=N; i++) {
			tmp=s.substring(0,s.length()-i+1)+t.substring(i,t.length());
			if(tmp.length()>=N) {
				if(tmp.substring(0,N).equals(s) && tmp.substring(tmp.length()-N,tmp.length()).equals(t)) {
					ngs=Math.min(tmp.length(), ngs);
				}
			}
			tmp=s.substring(0,s.length()-i)+t.substring(i-1,t.length());
			if(tmp.length()>=N) {
				if(tmp.substring(0,N).equals(s) && tmp.substring(tmp.length()-N,tmp.length()).equals(t)) {
					ngs=Math.min(tmp.length(), ngs);
				}
			}
			tmp=s.substring(0,s.length()-i)+t.substring(i,t.length());
			if(tmp.length()>=N) {
				if(tmp.substring(0,N).equals(s) && tmp.substring(tmp.length()-N,tmp.length()).equals(t)) {
					ngs=Math.min(tmp.length(), ngs);
				}
			}
		}
		System.out.println(ngs);
	}
}