import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x = in.nextInt();
		int sum = 0;
		int i = 1;
		while(sum < x){
			sum += i++;
		}
		System.out.println(i-1);
	}
}