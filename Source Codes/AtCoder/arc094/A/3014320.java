import java.util.*;
import java.lang.*;

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int[] abc = new int[3];
      abc[0] = Integer.parseInt(sc.next());
      abc[1] = Integer.parseInt(sc.next());
      abc[2] = Integer.parseInt(sc.next());
      Arrays.sort(abc);
      int difa = abc[2] - abc[0];
      int difb = abc[2] - abc[1];
      if(difa%2 == 0 && difb%2 == 0) System.out.println(difa/2 + difb/2);
      else if(difa%2 == 1 && difb%2 == 1) System.out.println(difa/2 + difb/2 + 1);
      else System.out.println(difa/2 + difb/2 + 2);
  }
}