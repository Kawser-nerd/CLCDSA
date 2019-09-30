import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    ArrayList<Integer> A = new ArrayList(N);

    for (int i=0; i<N; i++) {
      A.add(sc.nextInt());
    }
    
    int a = A.get(A.size()-1);
    for (int i=A.size()-2; i>=0; i--) {
      a = gcd(a, A.get(i));
    }

    System.out.println(a);
  }

  static int gcd(int a, int b) {
    if (b == 1) return 1;
    if (b == 0) return a;
    return gcd(b, a%b);
  }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.