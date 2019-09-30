import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;
       
       
       
       
       
      public class Main implements Runnable
      {
          static final long MAX = 464897L;
          static class InputReader
          {
              private InputStream stream;
              private byte[] buf = new byte[1024];
              private int curChar;
              private int numChars;
              private SpaceCharFilter filter;
              private BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       
              public InputReader(InputStream stream)
              {
                  this.stream = stream;
              }
              
              public int read()
              {
                  if (numChars==-1) 
                      throw new InputMismatchException();
                  
                  if (curChar >= numChars)
                  {
                      curChar = 0;
                      try 
                      {
                          numChars = stream.read(buf);
                      }
                      catch (IOException e)
                      {
                          throw new InputMismatchException();
                      }
                      
                      if(numChars <= 0)                
                          return -1;
                  }
                  return buf[curChar++];
              }
           
              public String nextLine()
              {
                  String str = "";
                  try
                  {
                      str = br.readLine();
                  }
                  catch (IOException e)
                  {
                      e.printStackTrace();
                  }
                  return str;
              }
              public int nextInt()
              {
                  int c = read();
                  
                  while(isSpaceChar(c)) 
                      c = read();
                  
                  int sgn = 1;
                  
                  if (c == '-') 
                  {
                      sgn = -1;
                      c = read();
                  }
                  
                  int res = 0;
                  do 
                  {
                      if(c<'0'||c>'9') 
                          throw new InputMismatchException();
                      res *= 10;
                      res += c - '0';
                      c = read();
                  }
                  while (!isSpaceChar(c)); 
                  
                  return res * sgn;
              }
              
              public long nextLong() 
              {
                  int c = read();
                  while (isSpaceChar(c))
                      c = read();
                  int sgn = 1;
                  if (c == '-') 
                  {
                      sgn = -1;
                      c = read();
                  }
                  long res = 0;
                  
                  do 
                  {
                      if (c < '0' || c > '9')
                          throw new InputMismatchException();
                      res *= 10;
                      res += c - '0';
                      c = read();
                  }
                  while (!isSpaceChar(c));
                      return res * sgn;
              }
              
              public double nextDouble() 
              {
                  int c = read();
                  while (isSpaceChar(c))
                      c = read();
                  int sgn = 1;
                  if (c == '-') 
                  {
                      sgn = -1;
                      c = read();
                  }
                  double res = 0;
                  while (!isSpaceChar(c) && c != '.') 
                  {
                      if (c == 'e' || c == 'E')
                          return res * Math.pow(10, nextInt());
                      if (c < '0' || c > '9')
                          throw new InputMismatchException();
                      res *= 10;
                      res += c - '0';
                      c = read();
                  }
                  if (c == '.') 
                  {
                      c = read();
                      double m = 1;
                      while (!isSpaceChar(c)) 
                      {
                          if (c == 'e' || c == 'E')
                              return res * Math.pow(10, nextInt());
                          if (c < '0' || c > '9')
                              throw new InputMismatchException();
                          m /= 10;
                          res += (c - '0') * m;
                          c = read();
                      }
                  }
                  return res * sgn;
              }
              
              public String readString() 
              {
                  int c = read();
                  while (isSpaceChar(c))
                      c = read();
                  StringBuilder res = new StringBuilder();
                  do 
                  {
                      res.appendCodePoint(c);
                      c = read();
                  } 
                  while (!isSpaceChar(c));
                  
                  return res.toString();
              }
           
              public boolean isSpaceChar(int c) 
              {
                  if (filter != null)
                      return filter.isSpaceChar(c);
                  return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
              }
           
              public String next() 
              {
                  return readString();
              }
              
              public interface SpaceCharFilter 
              {
                  public boolean isSpaceChar(int ch);
              }
          }
           
          public static void main(String args[]) throws Exception
          {
              new Thread(null, new Main(),"Main",1<<26).start();
          }   
          static long gcd(long a, long b) 
          { 
            if (b == 0) 
              return a; 
            return gcd(b, a % b);  
          } 
          static long lcm(long a,long b) {
            return (a/gcd(a,b) * b);
          }
          long MOD = 1000000007;
          ArrayList<Integer> adj[];
          long[] arr;
          long[] cost;
          public void run() 
          {
            InputReader sc = new InputReader(System.in);
          PrintWriter w = new PrintWriter(System.out);
          long a = sc.nextLong();
          long b = sc.nextLong();
          int ind = -1;
          for(int i = 61;i >= 0;i--) {
            if(((a >> i) & 1) != ((b >> i) & 1)) {
              ind = i;
              break;
            }
          }
          if(ind == -1) {
            w.println("1");
          }else {
            long r = power(2,ind,1000000000000000000L);
            long temp = r * 2 - 1;
            a = a & temp;
            b = b & temp;
            int rem = -1;
            for(int i = 0;i < ind;i++) {
              if(((b >> i) & 1) == 1) {
                rem = i;
              }
            }
            int rem2 = -1;
            for(int i = 0;i < ind;i++) {
              if(((a >> i) & 1) == 1) {
                rem2 = i;
              }
            }
            if(rem2 <= rem) {
              w.println(2*r-a);
            }else {
              temp = power(2,rem+1,1000000000000000000L) - 1;
              w.println(temp + 2*(r-a) + 1);
            }
          }
          w.close();
          }
          
          ArrayList<ArrayList<Integer>> common;
          ArrayList<Integer> ar;
          boolean[] visited;
          Stack<Integer> st;
          void dfs(int a){
          visited[a] = true;
          Iterator<Integer> it= adj[a].iterator();
          while(it.hasNext()){
            int n = it.next();
            if(!visited[n]){
              dfs(n);
            }
          }
          st.add(a);
        }
          
          static long power(long a,long b,long mod) {
          long ans = 1;
          a = a % mod;
          while(b != 0) {
            if(b % 2 == 1) {
              ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b = b/2;
          }
          return ans;
        }
          class Pair implements Comparable<Pair>{
              int a;
              int b;
              int c;
              int d;
              //int c;
              Pair(int a,int b,int c,int d){
                  this.b = b;
                  this.a = a;
                  this.c = c;
                  this.d = d;
              }
              public boolean equals(Object o) {
                  Pair p = (Pair)o;
                  return this.a == p.a && this.b == this.b;
              }
              public int hashCode(){
                  return Long.hashCode(a)*27 + Long.hashCode(b)*31;
              }
              public int compareTo(Pair p) {
                return Long.compare(this.c,p.c);
              }
          }
          
      }