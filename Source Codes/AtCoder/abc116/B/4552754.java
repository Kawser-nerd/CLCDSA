import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int s=sc.nextInt();
		int[]a=new int [1000000];
		int Answer=0;
		a[0]=s;
		loop:for(int i=1;i<a.length;i++) {
			if(a[i-1]%2==0) {
				a[i]=a[i-1]/2;
			}
			else if(a[i-1]%2!=0) {
				a[i]=a[i-1]*3+1;
			}
			for(int j=0;j<i;j++) {
				if(a[i]==a[j]) {
					Answer=i;
					break loop;
				}
				
			}
		
		}
		System.out.println(Answer+1);
	
		sc.close();
	}

}