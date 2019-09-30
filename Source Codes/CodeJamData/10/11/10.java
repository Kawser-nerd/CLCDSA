import java.io.*;


public class A_Rotate {
  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("test/A-large.in"));
    System.setOut(new PrintStream("test/A-large.out","ISO-8859-1"));
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    for (int c=0,T=Integer.parseInt(br.readLine()); c<T; c++) {
      String w[]=br.readLine().trim().split(" +");
      int N=Integer.parseInt(w[0]),K=Integer.parseInt(w[1]);
      char[][] m=new char[N][];
      for (int i=0; i<N; i++) {
        m[i]=br.readLine().trim().toCharArray();
        for (int j=N-1,k=N-1; j>=0; j--) if (m[i][j]!='.') {
          if (j!=k) {
            m[i][k]=m[i][j];
            m[i][j]='.';
          }
          k--;
        }
        //System.out.println(new String(m[i]));
      }
      int win=0;
      cicloExterno:for (int v=0; v<2; v++) {
        for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
          for (int di=-1; di<=1; di++) ciclo:for (int dj=-1; dj<=1; dj++) if (!(di==0&&dj==0)) {
            for (int a=i,b=j,k=0; k<K; k++,a+=di,b+=dj) {
              if (a<0||a>=N||b<0||b>=N||m[a][b]!=(v==0?'R':'B')) continue ciclo;
            }
            win|=(1<<v);
            continue cicloExterno;
          }
        }
      }
      String msg[]={"Neither","Red","Blue","Both"};
      System.out.print("Case #"+(c+1)+": "+msg[win]+"\r\n");
    }
    
  }
  
}
