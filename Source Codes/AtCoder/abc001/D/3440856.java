import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
  public static void main(String[] args) {
    final Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    TreeSet<String> set = new TreeSet<>();
    for (int i = 0; i < N; i++) {
      String SE = sc.next();
      set.add(getStartTime(SE) + "-" + getEndTime(SE));
    }
    sc.close();

    TreeSet<String> answer = new TreeSet<>();
    Iterator<String> itr = set.iterator();
    answer.add(itr.next());
    while (itr.hasNext()) {
      String next = itr.next();
      int nextStart = Integer.parseInt(next.substring(0, 4));
      int nextEnd = Integer.parseInt(next.substring(5));
      String last = answer.last();
      int lastEnd = Integer.parseInt(last.substring(5));
      if (nextStart <= lastEnd) {
        if (lastEnd < nextEnd) {
          answer.remove(last);
          answer.add(last.substring(0, 4) + "-" + next.substring(5));
        }
      } else {
        answer.add(next);
      }
    }

    Iterator<String> itr2 = answer.iterator();
    while (itr2.hasNext()) {
      System.out.println(itr2.next());
    }
  }

  private static String getStartTime(String SE) {
    switch (SE.charAt(3)) {
      case '1':
      case '2':
      case '3':
      case '4':
        return SE.substring(0, 3) + "0";
      case '6':
      case '7':
      case '8':
      case '9':
        return SE.substring(0, 3) + "5";
      default: // 0,5
        return SE.substring(0, 4);
    }
  }

  private static String getEndTime(String SE) {
    switch (SE.charAt(8)) {
      case '1':
      case '2':
      case '3':
      case '4':
        return SE.substring(5, 8) + "5";
      case '6':
      case '7':
      case '8':
      case '9':
        String hour = SE.substring(5, 7);
        switch (SE.charAt(7)) {
          case '0':
            return hour + "10";
          case '1':
            return hour + "20";
          case '2':
            return hour + "30";
          case '3':
            return hour + "40";
          case '4':
            return hour + "50";
          case '5':
            String newHour = "0" + String.valueOf(Integer.parseInt(hour) + 1);
            return newHour.substring(newHour.length() - 2) + "00";
        }
      default: // 0,5
        return SE.substring(5);
    }
  }
}