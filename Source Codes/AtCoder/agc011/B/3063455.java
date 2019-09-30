import java.io.*;
import java.util.*;
public class Main {
  public static void main(String[] args) throws Exception {
    String line = null;
    long sum = 0;
    int answer = 0;
    ArrayList<Integer> aList = new ArrayList<Integer>();

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    line = br.readLine();
    line = br.readLine();
    String data[] = line.split(" ");
    for (int i = 0; i < data.length; i ++) {
      int num = Integer.parseInt(data[i]);
      aList.add(num);
    }
    Collections.sort(aList);
    for (int i = 0; i < aList.size(); i++) {
      int num = aList.get(i);
      if (2 * sum >= num) {
        answer = answer + 1;
      } else {
        answer = 0;
      }
      sum = sum + num;
    }
    answer = answer + 1;
    System.out.println(answer);
  }
}