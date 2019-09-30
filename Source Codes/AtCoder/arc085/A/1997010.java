import java.io.*;
import java.math.BigInteger;
import java.util.*;
class Main
{
	static int power(int x, int y, int p)
	{
	    int res = 1;      // Initialize result
	 
	    x = x % p;  // Update x if it is more than or
	                // equal to p
	 
	    while (y > 0)
	    {
	        // If y is odd, multiply x with result
	        if (y%2== 1)
	            res = (res*x) % p;
	 
	        // y must be even now
	        y = y>>1; // y = y/2
	        x = (x*x) % p;
	    }
	    return res;
	}
	 
	// Returns n^(-1) mod p
	static int modInverse(int n, int p)
	{
	    return power(n, p-2, p);
	}
	 
	static // Returns nCr % p using Fermat's little
	// theorem.
	int nCr(int n, int r, int p)
	{
	   // Base case
	   if (r==0)
	      return 1;
	 
	    // Fill factorial array so that we
	    // can find all factorial of r, n
	    // and n-r
	    int fac[]=new int[n+1];
	    fac[0] = 1;
	    for (int i=1 ; i<=n; i++)
	        fac[i] = fac[i-1]*i%p;
	 
	    return (fac[n]* modInverse(fac[r], p) % p *
	            modInverse(fac[n-r], p) % p) % p;
	}
	static int countSetBits(int n)
	{
	    int count = 0;
	    while (n!=0)
	    {
	      n &= (n-1) ;
	      count++;
	    }
	    return count;
	}
	static int countsteps(int a)
	{
		if(a==1)
			return 0;
		return countsteps(countSetBits(a))+1;
	}
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int n=in.nextInt();
		int m=in.nextInt();
		System.out.println((1<<m)*(1900*m+100*(n-m)));
	}
	static StringBuilder ans=new StringBuilder();
	static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	        StringTokenizer st;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String next() throws IOException
	        {
	        	while(st==null||!st.hasMoreElements())
	        	{
	        		try
	        		{
	        			st=new StringTokenizer(readLine());
	        		}
	        		catch(IOException e)
	        		{
	        			e.printStackTrace();
	        		}
	        	}
	        	return
	        			st.nextToken();
	        }
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[65535]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.')
	            {
	                while ((c = read()) >= '0' && c <= '9')
	                {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	    }
}