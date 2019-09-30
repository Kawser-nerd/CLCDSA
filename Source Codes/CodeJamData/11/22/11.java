import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

   final double EPS = 1e-9;

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
          int C = sc.nextInt();
          int D = sc.nextInt();
          //CL[] tbl = new CL[C];
          ArrayList<Integer> ps = new ArrayList<Integer>();
          for(int i = 0; i < C; i++){
            //tbl[i] = new CL(sc.nextInt(), sc.nextInt());
            int P = sc.nextInt();
            int V = sc.nextInt();
            for(int j = 0; j < V; j++)ps.add(P);
          }
          //Arrays.sort(tbl);
          Collections.sort(ps);
          //for(int i = 0; i < ps.size(); i++)System.out.print(ps.get(i) + " ");
          //System.out.println();
          double left = 0, right = 1e13;
          double ans = right*2;
          for(int e = 0; e < 200; e++){
            double m = (left + right) / 2;
            if(ok(ps, D, m)){
              right = m;
              ans = min(m, ans);
            }else{
              left = m;
            }
          }
          System.out.printf("Case #%d: %f\n", o, ans);
        }
    }
    
    boolean ok(ArrayList<Integer> ps, int D, double len){
      double last = ps.get(0) - len;
      for(int i = 1; i < ps.size(); i++){
        double p = ps.get(i);
        //if(p - last + len < D + EPS || p + len < last + D + EPS)return false;
        if(p - last + len < D + EPS)return false;
        if(p - last - len > D - EPS){
          last = p - len;
        }else{
          last += D;
        }
      }
      return true;
    }
}

class CL implements Comparable<CL>{
  int pos;
  int num;
  CL(int p, int v){
    pos = p;
    num = v;
  }
  public int compareTo(CL cl){
    return  this.pos - cl.pos;
  }
}
