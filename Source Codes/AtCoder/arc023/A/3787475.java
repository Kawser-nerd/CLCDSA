import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int y=sc.nextInt();
		int m=sc.nextInt();
		int d=sc.nextInt();
		int res=365*2014+2014/4-2014/100+2014/400+(306*6)/10+17-429;
		int kk=0;
		if(m>2) {
			kk=365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;
		}
		else {
			y--;
			m+=12;
			kk=365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;
		}
		System.out.println(res-kk);
	}
}