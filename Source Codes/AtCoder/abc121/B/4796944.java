import java.io.PrintWriter;
import java.util.*;

/**
 * Hello AtCoder.
 *
 * @author kaito0228
 */
public class Main {
  public static void main(String[] args) {
    try (PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in)) {
      solve(sc, out);
      out.flush();

    } catch (Exception e) {
      // DO NOT USE
      e.printStackTrace();
    }
  }

  private static void solve(Scanner sc, PrintWriter out) {
    // TODO
    int n = nint(sc);
    int m = nint(sc);
    int c = nint(sc);
    List<Integer> list = getIntegerList(sc, m);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int a = 0;
      for (int j = 0; j < m; j++) {
        a += nint(sc) * list.get(j);
      }
      if (a + c > 0) {
        ans++;
      }
    }

    out.println(ans);
  }

  // method
  /**
   * Returns an int. int????????????
   *
   * @param sc Scanner
   * @return int
   */
  private static int nint(Scanner sc) {
    return Integer.parseInt(sc.next());
  }

  /**
   * Returns a long. long????????????
   *
   * @param sc Scanner
   * @return long
   */
  private static long nlong(Scanner sc) {
    return Long.parseLong(sc.next());
  }

  /**
   * Returns a double. double????????????
   *
   * @param sc Scanner
   * @return double
   */
  private static double ndouble(Scanner sc) {
    return Double.parseDouble(sc.next());
  }

  /**
   * Returns a String. ??????????????
   *
   * @param sc Scanner
   * @return String
   */
  private static String nstr(Scanner sc) {
    return sc.next();
  }

  /**
   * Returns a int array. int?????????????????
   *
   * @param sc Scanner
   * @param length Array length
   * @return int array
   */
  private static int[] intLine(Scanner sc, int length) {
    int[] iLine = new int[length];
    for (int i = 0; i < length; i++) {
      iLine[i] = nint(sc);
    }
    return iLine;
  }

  /**
   * Returns a long array. long?????????????????
   *
   * @param sc Scanner
   * @param length Array length
   * @return long array
   */
  private static long[] longLine(Scanner sc, int length) {
    long[] lLine = new long[length];
    for (int i = 0; i < length; i++) {
      lLine[i] = nlong(sc);
    }
    return lLine;
  }

  /**
   * Returns a String array. ???????????????????
   *
   * @param sc Scanner
   * @param length Array length
   * @return String array
   */
  private static String[] strLine(Scanner sc, int length) {
    String[] strLine = new String[length];
    for (int i = 0; i < length; i++) {
      strLine[i] = nstr(sc);
    }
    return strLine;
  }

  /**
   * Returns the maximum value in the list. ??????????????
   *
   * @param longList List
   * @return long maximum value
   */
  private static long maxFromList(List<Long> longList) {
    return longList.stream().max(Comparator.naturalOrder()).get();
  }

  /**
   * Returns the minimum value in the list. ??????????????
   *
   * @param longList List
   * @return long minimum value
   */
  private static long minFromList(List<Long> longList) {
    return longList.stream().min(Comparator.naturalOrder()).get();
  }

  /**
   * Returns the sum of each digit. ??????????
   *
   * @param n int
   * @return sum of each digit
   */
  private static int sumDigits(int n) {
    int sum = 0;
    while (n != 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

  /**
   * Returns the sum of each digit. ??????????
   *
   * @param n long
   * @return sum of each digit
   */
  private static long sumDigits(long n) {
    long sum = 0;
    while (n != 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

  /**
   * Return a list of Integer. Integer??????????
   *
   * @param sc Scanner
   * @param size list size
   * @return list
   */
  private static List<Integer> getIntegerList(Scanner sc, int size) {
    List<Integer> list = new ArrayList<>();
    for (int i = 0; i < size; i++) {
      list.add(nint(sc));
    }
    return list;
  }

  /**
   * Return a list of Long. Long??????????
   *
   * @param sc Scanner
   * @param size list size
   * @return list
   */
  private static List<Long> getLongList(Scanner sc, int size) {
    List<Long> list = new ArrayList<>();
    for (int i = 0; i < size; i++) {
      list.add(nlong(sc));
    }
    return list;
  }

  /**
   * Returns the summation of list. ????????????????
   *
   * @param list List<Integer>
   * @return sum of list
   */
  private static int sumList(List<Integer> list) {
    int sum = 0;
    for (Integer n : list) {
      sum += n;
    }
    return sum;
  }

  /**
   * Returns the average of list. ????????????????
   *
   * @param list List<Integer>
   * @return average of list
   */
  private static double aveList(List<Integer> list) {
    return (double) sumList(list) / list.size();
  }

  /**
   * Returns the greatest common divisor of the two given values. ???2???????????????
   *
   * @param m long
   * @param n long
   * @return greatest common divisor
   */
  private static long gcd(long m, long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
  }

  /**
   * Returns the least common multiple of the two given values. ???2???????????????
   *
   * @param m long
   * @param n long
   * @return least common multiple
   */
  private static long lcm(long m, long n) {
    return m * n / gcd(m, n);
  }

  /**
   * Returns the most frequent value in the list. ????????????????
   *
   * @param list List
   * @return most frequent value
   */
  private static Integer mode(List<Integer> list) {
    switch (list.size()) {
      case 0:
        throw new IllegalArgumentException();
      case 1:
        return list.get(0);
      default:
        Integer[] x = new Integer[list.size()];
        list.toArray(x);
        Arrays.sort(x);

        int maxValue = 1,
            maxKey = x[x.length - 1],
            previousKey = x[x.length - 1],
            breakPoint = x.length - 1;
        for (int i = x.length - 2; i >= 0; --i) {
          if (previousKey != x[i]) {
            if (maxValue < breakPoint - i) {
              maxValue = breakPoint - i;
              maxKey = x[i + 1];
            }
            previousKey = x[i];
            breakPoint = i;
          }
        }
        return breakPoint + 1 > maxValue ? x[0] : maxKey;
    }
  }

  private static Map<Integer, Integer> primeFactorize(long num) {
    Map<Integer, Integer> map = new HashMap<>();
    int i = 2;
    while (i * i <= num) {
      while (num % i == 0) {
        num /= i;
        if (map.containsKey(i)) {
          int tmp = map.get(i);
          tmp++;
          map.put(i, tmp);
        } else {
          map.put(i, 1);
        }
      }
      i++;
    }
    if (num > 1) map.put((int) num, 1);
    return map;
  }

  /**
   * Returns "YES" or "NO". ????????YES,NO??????
   *
   * @param bool boolean
   * @return "YES" or "NO"
   */
  private static String upperYESNO(boolean bool) {
    return bool ? "YES" : "NO";
  }

  /**
   * Returns "Yes" or "No". ????????Yes,No??????
   *
   * @param bool boolean
   * @return "Yes" or "No"
   */
  private static String pascalYesNo(boolean bool) {
    return bool ? "Yes" : "No";
  }
}