import java.util.*;
import java.io.*;
public class C{
  public static void main(String args[]) throws Exception{
    System.setIn(new FileInputStream("C2.in"));
    System.setOut(new PrintStream("C2.out"));
    Scanner sn=new Scanner(System.in);
    int t=sn.nextInt();
    for(int tt=1;tt<=t;tt++){
      TreeMap<Long,Long>mp=new TreeMap<>();
      long n=sn.nextLong();
      long k=sn.nextLong();
      mp.put(n,1l);
      long mini=-1;
      long maxi=-1;
      while(true){
        long len=mp.lastKey();
        long cnt=mp.get(len);
        if(k<=cnt){
          mini=(len-1)/2;
          maxi=len/2;
          break;
        }
        k-=cnt;
        mp.remove(len--);
        long cur=0;
        if(mp.containsKey(len/2))cur=mp.get(len/2);
        mp.put(len/2,cur+cnt);
        cur=0;
        if(mp.containsKey((len+1)/2))cur=mp.get((len+1)/2);
        mp.put((len+1)/2,cur+cnt);
      }
      System.out.println("Case #"+tt+": "+maxi+" "+mini);
    }
  }
}
