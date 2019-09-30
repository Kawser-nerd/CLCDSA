/*

Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class A
{
    public PrintStream out = System.out;
    public PrintStream err = System.err;
    public Scanner in = new Scanner(System.in);
    public DecimalFormat fmt = new DecimalFormat("0.000000000");
    
    public int n;
    public char[] who;
    public int[] pos;
    
    public void main()
    {
        try
        {
//          err = new PrintStream(new FileOutputStream("error.log"), true);			
            int TCase,cc;
            

            TCase = in.nextInt();
            for(cc = 1; cc <= TCase; ++cc)
            {
            	n = iInt();
            	who = new char[n];
            	pos = new int[n];
            	
            	for(int i = 0; i < n; ++i)
            	{
            		who[i] = iToken().charAt(0);
            		pos[i] = iInt();
            	}
            	
            	int i, j, x, y;
            	
            	x = y = 1;
            	i = next(0, 'O');
            	j = next(0, 'B');
            	
            	int steps = 0;
            	while(i < n && j < n)
            	{
            		if(i < j)
            		{
            			//Orange first
            			if(x == pos[i]) { i = next(i+1, 'O'); }
            			else { x = move(x, pos[i]); }
            			
            			//blue always move
            			y = move(y, pos[j]);
            		}
            		else
            		{
            			//blue first
            			if(y == pos[j]) { j = next(j + 1, 'B'); }
            			else  { y = move(y, pos[j]); }
            			
            			//orange always moves
            			x = move(x, pos[i]);
            		}
            		
            		++steps;
            	}
            	
            	while(i < n)
            	{
            		steps += Math.abs(x - pos[i]) + 1;
            		x = pos[i];
            		i = next(i + 1, 'O');
            	}
            	
            	while(j < n)
            	{
            		steps += Math.abs(y - pos[j]) + 1;
            		y = pos[j];
            		j = next(j + 1, 'B');
            	}
            	
                out.println("Case #" + cc + ": " + steps);
            }//end for cc = 1 ... TCase
        }
        catch(Exception e) { e.printStackTrace(); }
    }//end public void main()

    public int next(int k, char c)
    {
    	while(k < n)
    	{
    		if(who[k] == c) return k;
    		++k;
    	}
    	
    	return n;
    }
    
    public int move(int x, int Tx)
    {
    	if(x == Tx) return x;
    	if(x < Tx) return x + 1;
    	return x - 1;
    }
    
    public static void main(String[] args)
    {
        long startTime = System.currentTimeMillis();
        (new A()).main();
        long endTime = System.currentTimeMillis();
        
        long ms = endTime - startTime;
        long sec = ms/1000; ms = ms%1000;
        long min = sec/60; sec = sec%60;

        System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
    }
    
    public int    iInt()   { return in.nextInt(); }
    public long   iLong()  { return in.nextLong(); }
    public String iToken() { return in.next(); }
    public String iLine()  { return in.nextLine(); }    
}//ends public class ???
