import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	long a[]= {scan.nextInt(),scan.nextInt(),scan.nextInt()};
	long ans=0;
	Arrays.sort(a);
	if(a[0]%2==0||a[1]%2==0||a[2]%2==0) {
		ans=0;
	}
	else {
		ans=a[0]*a[1];
	}
	System.out.println(ans);
	}
}