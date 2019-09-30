/**
 * @(#)Loadtest.java
 *
 *
 * @author 
 * @version 1.00 2010/5/23
 */

import java.io.*;
import java.util.Scanner;

public class Loadtest {

    public Loadtest() {
    }
    
    public static int numIterations(long l, long p, int c)
    {
    	int counter = 0;
    	int accumulator = c;
    	double pdoub = p*1.0;
    	while(pdoub/l > c)
    	{
    		pdoub = pdoub/accumulator;
    		accumulator *= accumulator;
    		counter += 1;
    	}
    	return counter;
    }
    
    public static void main(String[] args){
    	String filename = args[0];
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	for(int i = 0; i < numCases; i++)
    	{
    		long L = sc.nextLong();
    		long P = sc.nextLong();
    		int C = sc.nextInt();
    		System.out.print("Case #" + (i+1) + ": ");
    		System.out.println(Loadtest.numIterations(L,P,C));
    	}
    	}
    	catch(Exception e){
    		System.out.println(e);
    	}
    	
    }
}