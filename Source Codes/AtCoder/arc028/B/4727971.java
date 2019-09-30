import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.PriorityQueue;
public class Main {
  public static void main(String[] args) {
    Main m = new Main();
    m.run();
  }
  
  private void run() {
    int n = 0;
    int k = 0;
    int[] x = new int[0];
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));) {
      String[] s = br.readLine().split("\\s+");
      n = Integer.parseInt(s[0]);
      k = Integer.parseInt(s[1]);
      x = Arrays.stream(br.readLine().split("\\s+"))
        .mapToInt(Integer::parseInt).toArray();
    } catch (IOException e) {
      e.printStackTrace();
    }
    PriorityQueue<Person> pq = new PriorityQueue<>();
    for (int i=0;i<k;i++) {
      pq.add(new Person(x[i],i+1,x[i]));
    }
    Person p = pq.poll();
    System.out.println(p.rank);
    for (int i=k;i<n;i++) {
      if (p.age > x[i]) {
        pq.add(new Person(x[i],i+1,x[i]));
        p = pq.poll();
      }
      System.out.println(p.rank);
    }
  }
  
  private class Person implements Comparable<Person> {
    private int age;
    private int rank;
    private int priority;
    private Person(int age,int rank,int priority) {
      this.age = age;
      this.rank = rank;
      this.priority = priority;
    }
    
    @Override
    public int compareTo(Person other) {
      return -this.priority+other.priority;
    }
  }
}