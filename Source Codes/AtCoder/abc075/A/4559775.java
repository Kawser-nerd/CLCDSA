import java.io.PrintWriter;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int r = Integer.parseInt(sc.next());
		int g = Integer.parseInt(sc.next());
      	int b = Integer.parseInt(sc.next());
		boolean a1 = r == g;
      	boolean a2 = g == b;
      	boolean a3 = b == r;
      	if(a1 && !a2 && !a3){
          out.println(b);
        }else if(!a1 && a2 && !a3){
          out.println(r);
        }else if(!a1 && !a2 && a3){
          out.println(g);
        }
		out.flush();	
	}
}