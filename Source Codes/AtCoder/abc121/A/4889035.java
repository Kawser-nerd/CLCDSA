import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// ??????
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int h = sc.nextInt();
		int w = sc.nextInt();
		
		int res = (H-h) * (W-w);
		
		System.out.println(res);
	}
	
}