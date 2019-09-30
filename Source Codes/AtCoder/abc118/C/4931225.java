import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] a = new int[N];
    for(int i = 0; i < N; i++ ){
      a[i] = sc.nextInt();
    }
    Main abc118C = new Main();
    System.out.println(abc118C.solve(a));
  }

  public int solve(int[] a) {
    ABC118CSolve abc118CSolve = new ABC118CSolve();
    return abc118CSolve.solve(a);
  }

  class ABC118CSolve{
    public int solve(int[] a){
      while(a.length != 1){
        Arrays.sort(a);
        Integer min = a[0];
        List<Integer> next = new ArrayList();
        next.add(min);

        for(int i=1; i < a.length; i++ ){
          int b = a[i] % min;
          if(b > 0) next.add(b);
        }
        a = new int[next.size()];
        for(int j = 0; j < next.size(); j++ ){
          a[j] = next.get(j);
        }
      }
      return a[0];
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.