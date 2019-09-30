import java.io.File;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;
import java.util.Map.Entry;

public class Main{
	
	public static void main(String[] args) throws IOException{
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		int[] bitIsOpen = new int[N];
		int[][] P = new int[N][11];
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < 10; j++){
				bitIsOpen[i] += in.nextInt() << j;
			}
			//System.out.println(Integer.toBinaryString(bitIsOpen[i]));
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < 11; j++){
				P[i][j] = in.nextInt();
			}
		}
		
		long max = Integer.MIN_VALUE;
		for(int bit = 1; bit <= 0b1111111111; bit++){
			long count = 0;
			//System.out.println("pattern:" + Integer.toBinaryString(bit));
			
			for(int i = 0; i < N; i++){
				int bitIslap = bitIsOpen[i] & bit;
				//System.out.println("mattch:" + Integer.toBinaryString(bitIslap));
				int c = 0;
				for(int j = 0; j < 10; j++){
					c += 1 & (bitIslap >> j);
				}
				//System.out.println(c);
				
				count += P[i][c];
			}
			if(count > max){
				max = count;
				//System.out.println("pattern:" + Integer.toBinaryString(bit));
			}
			//System.out.println(count);
		}
		
		System.out.println(max);
	}
}