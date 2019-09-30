import java.util.Scanner;
 
class Main{
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		long n=stdIn.nextLong(),t=stdIn.nextLong(),tmp=stdIn.nextLong(),a,i,s=0;
		for(i=1;i<n;i++) {
			a=stdIn.nextLong();
			if(t>a-tmp) s+=a-tmp;
			else s+=t;
			tmp=a;
		}
		s+=t;
		System.out.println(s);
	}
}