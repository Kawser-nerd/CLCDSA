package abishev.gcj2015.round2.p4;

import java.io.*;
import java.util.*;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

class D implements TaskFactory {
  @Override
  public Task create() {
    return new Task() {
      int r;
      int c;
      Set<String> ans;

      int[][] field;

      @Override
      public void input(Scanner input) {
        r = input.nextInt();
        c = input.nextInt();
        field = new int[r][c];
        ans = new HashSet<>();
      }

      @Override
      public void run() {
        run(0, 0);
      }

      private void run(int i, int j) {
        if (j == c) {
          // check, fill next level and go next
          for (int jj = 0; jj < c; jj++) {
            int sameCount = 0;
            if (i != 0 && field[i - 1][jj] == field[i][jj]) sameCount++;
            if (jj != 0 && field[i][jj - 1] == field[i][jj]) sameCount++;
            if (jj == 0 && field[i][c - 1] == field[i][jj]) sameCount++;
            if (jj != c - 1 && field[i][jj + 1] == field[i][jj]) sameCount++;
            if (jj == c - 1 && field[i][0] == field[i][jj]) sameCount++;

            if (i == r - 1 && sameCount != field[i][jj]) return;
            if (sameCount > field[i][jj]) return;
            if (sameCount < field[i][jj] - 1) return;
            if (sameCount == field[i][jj] - 1) {
              field[i + 1][jj] = field[i][jj];
            } else {
              if (i != r - 1) {
                field[i + 1][jj] = 0;
              }
            }
          }
          if (i == r - 1) {
            ans.add(codePosition());
            return;
          }

          run(i + 1, 0);
          return;
        }

        if (field[i][j] == 0) {
          if (i == 0 || field[i - 1][j] != 1) {
            field[i][j] = 1;
            run(i, j + 1);
          }
          if (i == 0 || field[i - 1][j] != 2) {
            field[i][j] = 2;
            run(i, j + 1);
          }
          if (i == 0 || field[i - 1][j] != 3) {
            field[i][j] = 3;
            run(i, j + 1);
          }
          field[i][j] = 0;
        } else {
          run(i, j + 1);
        }
      }

      private String codePosition() {
        String code = null;
        for (int start = 0; start < c; start++) {
          StringBuilder cur = new StringBuilder();
          for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
              cur.append(field[j][(i + start) % c]);
            }
          }
          if (code == null || code.compareTo(cur.toString()) < 0) {
            code = cur.toString();
          }
        }
        return code;
      }

      @Override
      public void output(PrintWriter output) {
        output.println(ans.size());
      }
    };
  }

  public static void main(String[] args) throws InterruptedException, IOException {
//    Runner.run(new D());
    Runner.run(new D(), "D-small-attempt0");
//    Runner.run(new D(), "D-large");
  }
}

interface TaskFactory {
  Task create();
}

interface Task {
  void input(Scanner input);

  void run();

  void output(PrintWriter output);
}

class Runner {
  public static void run(TaskFactory taskFactory, InputStream is, OutputStream os) throws InterruptedException {
    Scanner input = new Scanner(is);
    PrintWriter output = new PrintWriter(os);
    int t = input.nextInt();
    input.nextLine();
    List<Task> tasks = Collections.synchronizedList(new ArrayList<Task>());
    for (int tt = 1; tt <= t; tt++) {
      Task task = taskFactory.create();
      task.input(input);
      tasks.add(task);
    }

    final AtomicInteger doneTasks = new AtomicInteger(0);
    final CountDownLatch latch = new CountDownLatch(t);
    ExecutorService executor = Executors.newFixedThreadPool(8);
    for (final Task task : tasks) {
      executor.execute(new Runnable() {
        @Override
        public void run() {
          task.run();
          int doneTasksV = doneTasks.incrementAndGet();
          if (doneTasksV % 5 == 0) {
            System.out.println("done tasks: " + doneTasksV);
          }
          latch.countDown();
        }
      });
    }
    latch.await();
    executor.shutdown();

    int tt = 0;
    for (Task task : tasks) {
      output.print("Case #" + (++tt) + ": ");
      task.output(output);
      output.flush();
    }
  }

  public static void run(TaskFactory taskFactory) throws InterruptedException {
    run(taskFactory, System.in, System.out);
  }

  public static void run(TaskFactory taskFactory, String taskName) throws IOException, InterruptedException {
    FileInputStream is = new FileInputStream(new File(taskName + ".in"));
    FileOutputStream os = new FileOutputStream(new File(taskName + ".out"));
    run(taskFactory, is, os);
    is.close();
    os.close();
  }
}
