import java.util.*;
import java.io.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		a=a-b;
		for(;;) {
			a-=c;
			if(a<c) {
				break;
			}
				
		}
		System.out.println(a);
	}
}