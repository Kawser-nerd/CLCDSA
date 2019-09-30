import java.util.*;
import java.io.*;


public class Main{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		int d = Integer.parseInt(sc.next());
		if(a+b==c+d) {
			System.out.println("Balanced");
		}else if(a+b>c+d) {
			System.out.println("Left");
		}else if(a+b<c+d) {
			System.out.println("Right");
		}
		
	}
}