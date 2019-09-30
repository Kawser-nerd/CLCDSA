/**
 * @(#)Crossings.java
 *
 *
 * @author 
 * @version 1.00 2010/5/23
 */

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

public class Crossings {

    public Crossings() {
    }
    
    public static int numCrossings(ArrayList<int[]> wires)
    {
    	int answer = 0;
    	int ai = 0;
    	int bi = 0;
    	int aj = 0;
    	int bj = 0;
    	for(int i = 0; i < wires.size()-1; i++)
    	{
    		int[] current = wires.get(i);
    		ai = current[0];
    		bi = current[1];
    		for(int j = i+1; j < wires.size(); j++)
    		{
    			int[] check = wires.get(j);
    			aj = check[0];
    			bj = check[1];
    			if(ai > aj && bi < bj)
    			{
    				answer += 1;
    			}
    			else if(ai < aj && bi > bj)
    			{
    				answer += 1;
    			}
    		}
    	}
    	return answer;
    }
    
    public static void main(String[] args){
    	String filename = args[0];
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	
    	for(int i = 0; i < numCases; i++)
    	{
    		int numWires = sc.nextInt();
    		ArrayList<int[]> wires = new ArrayList<int[]>();
    		for(int j = 0; j < numWires; j++)
    		{
    			int[] currWire = new int[2];
    			currWire[0] = sc.nextInt();
    			currWire[1] = sc.nextInt();
    			wires.add(currWire);
    		}
    		int answer = Crossings.numCrossings(wires);
    		System.out.println("Case #" + (i+1) + ": " + answer);
    	}
    	
    	
    	}
    	catch(Exception e){
    		System.out.println(e);
    	}
    }
}