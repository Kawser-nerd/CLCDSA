import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		out.println((N-1)*(M-1));
		out.flush();	
	}
}