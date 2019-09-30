import java.io.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		String str = (new Scanner(System.in)).next();
		String ans = str.matches("^A[a-z]+C[a-z]+$") ? "AC" : "WA";
		System.out.println(ans);
	}
}