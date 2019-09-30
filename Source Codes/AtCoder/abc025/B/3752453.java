import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int min=sc.nextInt();
		int max=sc.nextInt();
		int now=0;
		for(int i=0; i<N; i++) {
			String a=sc.next();
			int id=sc.nextInt();
			if(id<min) {
				id=min;
			}
			else if(id>max) {
				id=max;
			}
			if(a.charAt(0)=='E') {
				now+=id;
			}
			else if(a.charAt(0)=='W') {
				now-=id;
			}
		}
		if(now>0) {
			System.out.println("East "+now);
		}
		else if(now<0) {
			System.out.println("West "+(now*-1));
		}
		else {
			System.out.println(0);
		}
	}
}