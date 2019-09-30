import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  static int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  static int[] factors = new int[primes.length];

  public static void main(String[] args) {

    int N = sc.nextInt();

    //N!??????
    for (int i=2; i<=N; i++) {
      int n = i;
      for (int j=0; j<primes.length; j++) {
        if (n % primes[j] == 0) {
          n /= primes[j];
          factors[j]++;
          j--;
          if (n == 1) break;
        }
      }
    }

    System.out.println(f(2, 4, 4) + f(4, 2, 4) + f(4, 4, 2) +
            g(4, 14) + g(14, 4) + g(2, 24) + g(24, 2) + h(74));

  }

  static int f(int a, int b, int c) {
    int ret = 0;
    for (int i=0; i<primes.length; i++) {
      for (int j=i+1; j<primes.length; j++) {
        for (int k=j+1; k<primes.length; k++) {
          if (factors[i] >= a && factors[j] >= b && factors[k] >= c) {
            ret++;
          }
        }
      }
    }
    return ret;
  }

  static int g(int a, int b) {
    int ret = 0;
    for (int i=0; i<primes.length; i++) {
      for (int j=i+1; j<primes.length; j++) {
        if (factors[i] >= a && factors[j] >= b) {
          ret++;
        }
      }
    }
    return ret;
  }

  static int h(int a) {
    int ret = 0;
    for (int i=0; i<primes.length; i++) {
      if (factors[i] >= a) {
        ret++;
      }
    }
    return ret;
  }

}