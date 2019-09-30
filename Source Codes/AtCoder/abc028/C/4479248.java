import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[5];
	int b[]=new int[10];
for(int i=0;i<5;i++) {
	a[i]=sc.nextInt();
}
int m=-1;
	for(int i=4;i>=2;i--) {
		for(int j=i-1;j>=1;j--) {
			for(int l=j-1;l>=0;l--) {
				m++;
				b[m]=a[i]+a[j]+a[l];
			}
		}
	}
	Arrays.sort(b);
	System.out.println(b[7]);
	}
}

// 0 1 2 3 4
// 432 431 430 421   420 410 321 320 310 210