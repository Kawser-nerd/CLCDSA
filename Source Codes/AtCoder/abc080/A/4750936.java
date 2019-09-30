import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		if(a*b<=c) {
			System.out.println(a*b);
		}else if(c < a*b) {
			System.out.println(c);
		}

	}
}