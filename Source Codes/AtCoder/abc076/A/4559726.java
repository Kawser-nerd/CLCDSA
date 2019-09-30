import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int r = Integer.parseInt(sc.next());
		int g = Integer.parseInt(sc.next());
		int ans =g*2 - r;
		out.println(ans);
		out.flush();	
	}
}