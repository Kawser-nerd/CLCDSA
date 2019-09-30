package qualification;

import java.io.*;
import java.util.*;

public class C_RecycledNumbers {
  //--------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="large";
  private static boolean STANDARD_OUTPUT=false;
  //--------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    int[][] results=new int[2000001][];
    for (int i=0; i<results.length; i++) {
      int array[]=new int[8],n=0;
      String s=""+i;
      loop:for (int p=1; p<s.length(); p++) if (s.charAt(p)!='0') {
        int j=Integer.parseInt(s.substring(p)+s.substring(0,p));
        if (j<=i) continue loop;
        for (int q=0; q<n; q++) if (array[q]==j) continue loop;
        if (array.length==n) array=Arrays.copyOf(array,n*2);
        array[n++]=j;
      }
      results[i]=Arrays.copyOf(array,n);
      Arrays.sort(results[i]);
    }
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().trim().split(" +");
      int A=Integer.parseInt(w[0]),B=Integer.parseInt(w[1]);
      int count=0;
      for (int i=A; i<=B; i++) {
        // Binary Search doesn't represent an improvement
        for (int x:results[i]) if (x<=B) count++;
      }
      System.out.println("Case #"+c+": "+count);
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
}
