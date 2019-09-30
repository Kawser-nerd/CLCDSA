import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			String str=sc.next();
			int cnt=0;
			for(int i=0;i<str.length();){
				cnt++; char now=str.charAt(i);
				while(i<str.length() && str.charAt(i)==now) i++;
			}
			System.out.println(cnt-1);
		}
	}
}