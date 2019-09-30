import java.util.*;
import java.io.*;
import java.math.*;
public class Main
{
    static class Reader 
    { 
        private InputStream mIs;private byte[] buf = new byte[1024];private int curChar,numChars;public Reader() { this(System.in); }public Reader(InputStream is) { mIs = is;} 
        public int read() {if (numChars == -1) throw new InputMismatchException();if (curChar >= numChars) {curChar = 0;try { numChars = mIs.read(buf);} catch (IOException e) { throw new InputMismatchException();}if (numChars <= 0) return -1; }return buf[curChar++];} 
        public String nextLine(){int c = read();while (isSpaceChar(c)) c = read();StringBuilder res = new StringBuilder();do {res.appendCodePoint(c);c = read();}while (!isEndOfLine(c));return res.toString() ;} 
        public String s(){int c = read();while (isSpaceChar(c)) c = read();StringBuilder res = new StringBuilder();do {res.appendCodePoint(c);c = read();}while (!isSpaceChar(c));return res.toString();} 
        public long l(){int c = read();while (isSpaceChar(c)) c = read();int sgn = 1;if (c == '-') { sgn = -1 ; c = read() ; }long res = 0; do{ if (c < '0' || c > '9') throw new InputMismatchException();res *= 10 ; res += c - '0' ; c = read();}while(!isSpaceChar(c));return res * sgn;} 
        public int i(){int c = read() ;while (isSpaceChar(c)) c = read();int sgn = 1;if (c == '-') { sgn = -1 ; c = read() ; }int res = 0;do{if (c < '0' || c > '9') throw new InputMismatchException();res *= 10 ; res += c - '0' ; c = read() ;}while(!isSpaceChar(c));return res * sgn;} 
        public double d() throws IOException {return Double.parseDouble(s()) ;}
        public boolean isSpaceChar(int c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1; } 
        public boolean isEndOfLine(int c) { return c == '\n' || c == '\r' || c == -1; } 
        public int[] arr(int n){int[] ret = new int[n];for (int i = 0; i < n; i++) {ret[i] = i();}return ret;}
    }
    
    
 
           //       |----|       /\      |    |   -----   |
           //       |   /       /  \     |    |     |     |
           //       |--/       /----\    |----|     |     |
           //       |   \     /      \   |    |     |     |
           //       |    \   /        \  |    |   -----   -------

    
    static int h,w,k;
    static long cache[][];
    static int mod =1000000007;
    public static long dp(int pos,int col)
    {
    	if(pos==h)
    	{
    		if(col==k)
    			return 1;
    		return 0;
    	}
    	if(cache[pos][col]!=-1)
    		return cache[pos][col];
    	long ans=0;
    	for(int i=0;i<(1<<(w-1));i++)
    	{
    		StringBuilder s=new StringBuilder(Integer.toString(i,2));
    		s=s.reverse();
    		while(s.length()<w)
    		s=s.append('0');
    		if(s.indexOf("11")!=-1)
    		continue;
    		if(s.charAt(col)=='1')
    		ans+=dp(pos+1,col+1);
    		else if(col!=0&&s.charAt(col-1)=='1')
    		ans+=dp(pos+1,col-1);
    		else
    		ans+=dp(pos+1,col);
    	}
    	return cache[pos][col]=ans%mod;
    }
    public static void main(String[] args)throws IOException
    {
        PrintWriter out= new PrintWriter(System.out);
        Reader sc=new Reader();
        h=sc.i();w=sc.i();k=sc.i();
        k--;
        cache=new long[h+1][w+1];
        for(int i=0;i<=h;i++)Arrays.fill(cache[i],-1l);
        out.println(dp(0,0));
        out.flush();
    }
}