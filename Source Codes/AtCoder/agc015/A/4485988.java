import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int A = scan.nextInt();
		int B = scan.nextInt();
		if(N==1)
	    {
	        if(A==B)
	           System.out.println(1);
	        else
	          System.out.println(0);
	    }
	    else 
	    {
	        if(A>B)
	            System.out.println(0);
	        else
	           System.out.println((long )(B-A)*(N-2)+1);;
	    }
//		if (start > end) {
//			System.out.println(0);
//		} else {
//			if (n == 1 && start != end) {
//				System.out.println(0);
//			} else {
//				System.out.println((long)(start + end * (n - 1)) - (long)(end + start * (n - 1)) + 1);
//			}
//
//		}
		//int max=Math.max(0,(start + end * (n - 1)) - (end + start * (n - 1)) + 1);
		//System.out.println(max);
	}

}