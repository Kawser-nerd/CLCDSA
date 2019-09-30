/*

Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class B
{
    public PrintStream out = System.out;
    public PrintStream err = System.err;
    public Scanner in = new Scanner(System.in);
    public DecimalFormat fmt = new DecimalFormat("0.000000000");
    
    public String input;
    public char[][] G;
    public boolean[][] bad;
    
    public int[] inList;
    public int n;
    
    public void main()
    {
        try
        {
//          err = new PrintStream(new FileOutputStream("error.log"), true);			
            int TCase,cc;
            int x, y;
        	G = new char[26][26];
        	bad = new boolean[26][26];
        	inList = new int[26];

            TCase = in.nextInt();
            for(cc = 1; cc <= TCase; ++cc)
            {
            	init(G, ' ');
            	
            	int Cn = iInt();
            	for(int i = 0; i < Cn; ++i)
            	{
            		String T = iToken();
            		x = code(T.charAt(0));
            		y = code(T.charAt(1));            		
            		G[x][y] = G[y][x] = T.charAt(2);
            	}
            	
            	int Dn = iInt();
            	init(bad, false);
            	for(int i = 0; i < Dn; ++i)
            	{
            		String T = iToken();
            		x = code(T.charAt(0));
            		y = code(T.charAt(1));            		
            		bad[x][y] = bad[y][x] = true;
            	}
            	
            	Arrays.fill(inList, 0);
            	
            	n = iInt();
            	input = iToken();
            	
            	ArrayList<Character> L = new ArrayList<Character>();
            	
            	for(int i = 0; i < n; ++i)
            	{
            		char c = input.charAt(i);
            		x = code(c);
            		
            		L.add(c);
            		inList[x]++;
            		
            		if(!combine(L)) oppose(L);
            	}
            	
                out.println("Case #" + cc + ": " + makeString(L));
            }//end for cc = 1 ... TCase
        }
        catch(Exception e) { e.printStackTrace(); }
    }//end public void main()

    public boolean combine(ArrayList<Character> L)
    {
    	int Ln = L.size();
    	if(Ln < 2) return false;
    	
    	int x = code(L.get(Ln - 2));
    	int y = code(L.get(Ln - 1));
    	
    	if(G[x][y] != ' ')
    	{
    		L.remove(Ln - 1);
    		L.remove(Ln - 2);
    		--inList[x];
    		--inList[y];
    		
    		int z = code(G[x][y]);    		
    		L.add(G[x][y]);
    		++inList[z];
    		return true;
    	}
    	
    	return false;
    }
    
    public void oppose(ArrayList<Character> L)
    {
    	int Ln = L.size();
    	if(Ln < 2) return;
    	
    	int x = code(L.get(Ln - 1));
    	for(int y = 0; y < 26; ++y) if(inList[y] > 0 && bad[x][y])
    	{
    		L.clear();
    		Arrays.fill(inList, 0);
    		return;
    	}
    }
    
    public String makeString(ArrayList<Character> L)
    {
    	StringBuffer res = new StringBuffer("[");
    	String comma = "";
    	
    	for(Character c : L)
    	{
    		res.append(comma + c);
    		comma = ", ";
    	}
    	
    	res.append("]");
    	
    	return res.toString();
    }
    
    public int code(char c) { return c - 'A'; }
    
    public static void main(String[] args)
    {
        long startTime = System.currentTimeMillis();
        (new B()).main();
        long endTime = System.currentTimeMillis();
        
        long ms = endTime - startTime;
        long sec = ms/1000; ms = ms%1000;
        long min = sec/60; sec = sec%60;

        System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
    }
    
	public void init(char[][] A, char val) 
	{ 
		for(int i=0;i<A.length;++i) Arrays.fill(A[i], val); 
	} 
	
	public void init(boolean[][] A, boolean val)
	{ 
		for(int i=0;i<A.length;++i) Arrays.fill(A[i], val); 
	}	
    
    public int    iInt()   { return in.nextInt(); }
    public long   iLong()  { return in.nextLong(); }
    public String iToken() { return in.next(); }
    public String iLine()  { return in.nextLine(); }    
}//ends public class ???
