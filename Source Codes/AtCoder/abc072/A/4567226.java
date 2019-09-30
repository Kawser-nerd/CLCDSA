import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int N = Integer.parseInt(sc.next());
		int T = Integer.parseInt(sc.next());
		if(N-T>0){
			out.println(N-T);
		}else{
			out.println(0);
		}
		out.flush();	
	}
}