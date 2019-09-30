import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class Robot {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        String[] problem = br.readLine().split("[, ]+");
        System.out.println("Case #" + (i+1) + ": " + solve(problem));
      }
    } finally {
      br.close();
    }
  }

  private static int solve(String[] problem) {
    int blueRobot = 1;
    int orangeRobot = 1;
    Queue<Integer> orangeTargets = new LinkedList<Integer>();
    Queue<Integer> blueTargets = new LinkedList<Integer>();
    Queue<Boolean> isNextTargetBlue = new LinkedList<Boolean>();
    for (int i = 1; i<problem.length; i+=2) {
      boolean nextTargetBlue = problem[i].equalsIgnoreCase("b");
      isNextTargetBlue.add(nextTargetBlue);
      if (nextTargetBlue) {
        blueTargets.add(Integer.parseInt(problem[i+1]));
      } else {
        orangeTargets.add(Integer.parseInt(problem[i+1]));
      }
    }
    int time = 0;
    debug(time, orangeRobot, blueRobot);
    while (!isNextTargetBlue.isEmpty()) {
      boolean nextTargetBlue = isNextTargetBlue.poll();
      if (nextTargetBlue) {
        while (blueRobot != blueTargets.peek()) {
          time++;
          if (blueTargets.peek() > blueRobot) {
            blueRobot++;
          } else if (blueTargets.peek() < blueRobot) {
            blueRobot--;
          }
          if (!orangeTargets.isEmpty()) {
            if (orangeTargets.peek() > orangeRobot) {
              orangeRobot++;
            } else if (orangeTargets.peek() < orangeRobot) {
              orangeRobot--;
            }
          }
          debug(time, orangeRobot, blueRobot);
        }
        time++;

        // blue button pushed
        blueTargets.poll();

        if (!orangeTargets.isEmpty()) {
          if (orangeTargets.peek() > orangeRobot) {
            orangeRobot++;
          } else if (orangeTargets.peek() < orangeRobot) {
            orangeRobot--;
          }
        }
      } else {
        while (orangeRobot != orangeTargets.peek()) {
          time++;
          if (!blueTargets.isEmpty()) {
            if (blueTargets.peek() > blueRobot) {
              blueRobot++;
            } else if (blueTargets.peek() < blueRobot) {
              blueRobot--;
            }
          }
          if (orangeTargets.peek() > orangeRobot) {
            orangeRobot++;
          } else if (orangeTargets.peek() < orangeRobot) {
            orangeRobot--;
          }
          debug(time, orangeRobot, blueRobot);
        }
        time++;

        // orange button pushed
        orangeTargets.poll();

        if (!blueTargets.isEmpty()) {
          if (blueTargets.peek() > blueRobot) {
            blueRobot++;
          } else if (blueTargets.peek() < blueRobot) {
            blueRobot--;
          }
        }
      }
    }
    return time;
  }

  private static void debug(int time, int orangeRobot, int blueRobot) {
    if (false) {
      System.out.println("@" + time + ": " + orangeRobot + " -- " + blueRobot);
    }
  }
}
