import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		long D = sc.nextLong();
		long X = sc.nextLong();
		long A[] = new long[N];
		
		for(int i=0;i<N;i++){
			A[i] = sc.nextLong();
		}
		for(int i=0;i<N;i++){
			X+= 1+((D-1)/A[i]);
		}
		out.println(X);
		out.flush();	
	}
}