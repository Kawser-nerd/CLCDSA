import java.util.*;
import java.io.*;


public class Main{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		if(0==(a*b)%2) {
		System.out.println("Even");
		}else {
			System.out.println("Odd");
		}
	}
}