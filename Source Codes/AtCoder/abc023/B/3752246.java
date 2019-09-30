import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int mjs=sc.nextInt();
		if(mjs%2==0) {
			System.out.println(-1);
			System.exit(0);
		}
		else {
			int times=(mjs-1)/2;
			String st="b";
			for(int i=1; i<=times; i++) {
				if(i%3==1) {
					st="a"+st+"c";
				}
				else if(i%3==2) {
					st="c"+st+"a";
				}
				else if(i%3==0) {
					st="b"+st+"b";
				}
			}
			if(st.equals(sc.next())) {
				System.out.println(times);
			}
			else {
				System.out.println(-1);
			}
		}
	}
}