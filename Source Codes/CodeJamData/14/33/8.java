package codejam;

import java.io.*;
import java.util.Scanner;

public abstract class Task {
  protected abstract String getName();

  protected abstract void runOne(Scanner input, PrintWriter output);

  void run(InputStream input, OutputStream output) {
    Scanner in = new Scanner(input);
    PrintWriter out = new PrintWriter(output);

    int testsCount = in.nextInt();
    in.nextLine();
    for (int test = 1; test <= testsCount; test++) {
      System.out.println("solving " + test);
      out.print("Case #" + test + ": ");
      runOne(in, out);
      out.flush();
    }
  }

  public static void runConsole(Task task) {
    task.run(System.in, System.out);
  }

  public static void runSmall(Task task, int num) throws IOException {
    runFiles(task,
        new File("./" + task.getName() + "-small-attempt" + num + ".in"),
        new File("./" + task.getName() + "-small-attempt" + num + ".out"));
  }

  public static void runLarge(Task task) throws IOException {
    runFiles(task,
        new File("./" + task.getName() + "-large.in"),
        new File("./" + task.getName() + "-large.out"));
  }

  private static void runFiles(Task task, File input, File output) throws IOException {
    InputStream is = new BufferedInputStream(new FileInputStream(input));
    OutputStream os = new BufferedOutputStream(new FileOutputStream(output));
    task.run(is, os);
    is.close();
    os.close();
  }
}
