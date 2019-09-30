import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    Student[] a = new Student[N];
    for (int i = 0; i < N; i++) a[i] = new Student(i + 1, scanner.nextInt());
    Arrays.sort(a, (s1, s2) -> s2.height - s1.height);

    for (int i = 0; i < N; i++) System.out.println(a[i].id);
  }

  private static class Student {
    public final int id;
    final int height;

    private Student(int id, int height) {
      this.id = id;
      this.height = height;
    }
  }
}