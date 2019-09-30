import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a[]= {1,2,3,4,5,6};
		int N=sc.nextInt()%30;
		for(int i=0;i<N;i++) {
			int temp=a[(i%5)];
			a[(i%5)]=a[(i%5+1)];
			a[(i%5+1)]=temp;
		}
		System.out.println(a[0]+""+a[1]+""+a[2]+""+a[3]+""+a[4]+a[5]);
	}
}