import java.io.*;

public class B_MakeItSmooth {
  static long D,I,mins[][]=new long[1000][257];
  static int N,M,X=256,m[]=new int[1000];
  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("test/B-large.in"));
    System.setOut(new PrintStream("test/B-large.out","ISO-8859-1"));
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    for (int c=0,T=Integer.parseInt(br.readLine()); c<T; c++) {
      String w[]=br.readLine().trim().split(" +");
      D=Long.parseLong(w[0]);
      I=Long.parseLong(w[1]);
      M=Integer.parseInt(w[2]);
      N=Integer.parseInt(w[3]);
      w=br.readLine().trim().split(" +");
      for (int i=0; i<N; i++) m[i]=Integer.parseInt(w[i]);
      for (int i=0; i<=N; i++) {
        for (int s=0; s<=X; s++) { // arr[0..i]
          if (i==0) {
            mins[i][s]=0L;
          }
          else {
            long MIN=Long.MAX_VALUE;
            if (mins[i-1][s]!=Long.MAX_VALUE) {
              MIN=D+mins[i-1][s];
            }
            for (int v=0; v<X; v++) if (mins[i-1][v]!=Long.MAX_VALUE) {
              if (M>0) {
                MIN=Math.min(MIN,Math.abs(m[i-1]-v)+(v==s||s==X?0:I*((Math.abs(v-s)-1)/M))+mins[i-1][v]);
              }
              else if (v==s||s==X) {
                MIN=Math.min(MIN,Math.abs(m[i-1]-v)+0+mins[i-1][v]);
              }
            }
            mins[i][s]=MIN;
          }
          
        }
      }
      System.out.print("Case #"+(c+1)+": "+mins[N][X]+"\r\n");
    }
  }
}
