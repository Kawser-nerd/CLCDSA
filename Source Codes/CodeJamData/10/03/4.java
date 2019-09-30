package qualification.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class CLarge {
	
	Scanner in;	
	
	public CLarge() {		
		in = new Scanner(System.in);
		
		int t = in.nextInt();
		for(int l=1;l<=t;l++){
			int r = in.nextInt();
			int k = in.nextInt();
			int n = in.nextInt();
			
			int[] arr = new int[n];
			for(int i=0;i<n;i++){
				arr[i] = in.nextInt();
			}
			
			int[] nextGroup = new int[n];
			long[] money = new long[n];
			
			//long[] selfCycle = new long[n];
						
			for(int i=0;i<n;i++){
				long space = k;
				int pointer = i;
				long total = 0;
				int srcPointer = pointer;
				while(space>=arr[pointer]){
					
					space -= arr[pointer];
					total += arr[pointer];
					
					if((pointer+1)%n == srcPointer){
						break;
					}
					
					pointer = (pointer+1)%n;					
					
				}	
				
				nextGroup[i] = pointer;
				money[i] = total;				
			}
			
			
			int group = 0;
		long total = 0;
			for(int i=0;i<r;i++){
				total += money[group];
				group = nextGroup[group];
			}
			
			
			
			
			System.out.printf("Case #%d: %d\n", l, total);
			
		}
	}

	public static void main(String[] args) {
		
		try {
			/*
			 * sample
			 * ?-small-practice
			 * ?-large-practice
			 */		
			String p = "C-large-practice";		
			System.setIn(CLarge.class.getResourceAsStream(p+".in"));
			System.setOut(new PrintStream(new File("src/qualification/c/"+p+".out")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
		
		new CLarge();
	}

}
