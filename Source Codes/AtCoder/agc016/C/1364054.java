import java.util.*;
import java.io.*;
import java.math.*;

public class Main{

  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    Integer[] HWhw = Arrays.stream(in.readLine().split(" ")).map(Integer::parseInt).toArray(Integer[]::new);

    int H = HWhw[0];
    int W = HWhw[1];
    int h = HWhw[2];
    int w = HWhw[3];

    long[][] rect = new long[H][W];

    long large = (long)Math.pow(10L, 9)-1;

    if (H%h==0 && W%w==0) {
      System.out.println("No");
    }else{
      System.out.println("Yes");
      for(int i=0;i<H;i+=h){
        for(int j=0;j<W;j+=w){
          rect[i][j] = large;
        }
      }
      for(int i=h-1;i<H;i+=h){
        for(int j=w-1;j<W;j+=w){
          rect[i][j] -= (large+1);
        }
      }
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          System.out.print(rect[i][j]+" ");
        }
        System.out.println();
      }
    }
  }
}