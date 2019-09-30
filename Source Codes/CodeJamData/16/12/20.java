import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Rank {
	public static void main(String [] args) throws IOException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		
		int cs = input.nextInt();
		for(int i = 1; i <= cs; i++) {
			int[] arr = new int[2501];
			int sz = input.nextInt();
			for(int x = 0; x < sz * (2 * sz - 1); x++) {
				arr[input.nextInt()]++;
			}
			out.printf("Case #%d:", i);
			for(int j = 0; j < arr.length; j++)
				if(arr[j] % 2 == 1)
					out.print(" " + j);
			out.println();
		}
		out.close();
	}
}
