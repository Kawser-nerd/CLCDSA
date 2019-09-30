// by agus.mw
import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws Exception {
    new Main().doWork();
  }
  void doWork() throws Exception{
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    
    int ncase = Integer.valueOf(reader.readLine().trim());
    for(int icase=0;icase<ncase;icase++){
      int[] p = toIntArray(reader.readLine().trim());
      int N = p[0];
      int M = p[1];
      int[][] ns = new int[N][];
      int[][] ms = new int[M][];
      for(int i=0;i<N;i++) ns[i] = toIntArray(reader.readLine().trim());
      for(int i=0;i<M;i++) ms[i] = toIntArray(reader.readLine().trim());
      String out = process(ns,ms);
      out = "Case #"+(icase+1)+": "+out+"\r\n";
      writer.write(out,0,out.length());
    }
    
    writer.flush();
    writer.close();
    reader.close();
  }
  String process(int[][] ns, int[][] ms){
    String out = "";
    for(int im=0;im<ms.length;im++){
      double area = 0;
      double[] q = toD(ms[im]);
      double[] a = toD(ns[0]);
      double[] b = toD(ns[1]);
      area += areaOf(q,a,b);
      area += areaOf(q,b,a);
      if(im>0) out += " ";
      out += String.format("%.7f",area);
    }
    return out;
  }
  double areaOf(double[] q, double[] a, double[] b){
    double[] ab = sub(b,a);
    double[] aq = sub(q,a);
    double cos = dot(ab,aq)/abs(ab)/abs(aq);
    double theta = Math.acos(cos);
    return (theta-cos*Math.sin(theta))*abs(aq)*abs(aq);
  }
  double dot(double[] b,double[] a){
    return a[0]*b[0]+b[1]*a[1];
  }
  double abs(double[] c){
    return Math.sqrt(dot(c,c));
  }
  double[] sub(double[] b,double[] a){
    return new double[]{b[0]-a[0],b[1]-a[1]};
  }
  double[] toD(int[] a){
    return new double[]{a[0],a[1]};
  }
  int[] toIntArray(String line){
    String[] p = line.split("[ ]+");
    int[] out = new int[p.length];
    for(int i=0;i<p.length;i++) out[i] = Integer.valueOf(p[i]);
    return out;
  }
}