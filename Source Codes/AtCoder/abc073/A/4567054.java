import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int N = Integer.parseInt(sc.next());
		if(N%10==9 || N>=90){
			out.println("Yes");
		}else{
			out.println("No");
		}
		out.flush();	
	}
}