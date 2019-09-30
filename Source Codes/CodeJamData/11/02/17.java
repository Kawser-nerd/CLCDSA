import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class Magicka {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        String[] problem = br.readLine().split("[ ]+");
        Integer[][] combine = new Integer[26][26];
        Set<Integer> repel = new HashSet<Integer>();
        int numCombine = Integer.parseInt(problem[0]);
        for (int j = 0; j<numCombine; j++) {
          int letter1 = problem[j+1].charAt(0)-'A';
          int letter2 = problem[j+1].charAt(1)-'A';
          Integer result = problem[j+1].charAt(2) - 'A';
          combine[letter1][letter2] = combine[letter2][letter1] = result;
        }
        int numRepel = Integer.parseInt(problem[1 + numCombine]);
        for (int j = 0; j<numRepel; j++) {
          int letter1 = problem[1 + numCombine + j + 1].charAt(0)-'A';
          int letter2 = problem[1 + numCombine + j + 1].charAt(1)-'A';
          repel.add(26 * letter1 + letter2);
          repel.add(26*letter2 + letter1);
        }

        String moves = problem[problem.length-1];

        System.out.println("Case #" + (i+1) + ": " + solve(combine, repel, moves));
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }

  private static String solve(Integer[][] combine, Set<Integer> repel, String moves) {
    int[] counts = new int[26];
    List<Integer> elementList = new ArrayList<Integer>();
    for (int i = 0; i<moves.length(); i++) {
      int move = moves.charAt(i) - 'A';
      elementList.add(move);
      counts[move]++;
      while (elementList.size() >= 2) {
        int m1 = elementList.get(elementList.size()-1);
        int m2 = elementList.get(elementList.size()-2);
        if (combine[m1][m2] != null) {
          elementList.remove(elementList.size()-1);
          elementList.remove(elementList.size()-1);
          counts[m1]--;
          counts[m2]--;
          counts[combine[m1][m2]]++;
          elementList.add(combine[m1][m2]);
        } else {
          break;
        }
      }
      for (Integer repulsion : repel) {
        if (counts[repulsion%26] > 0 && counts[repulsion/26] > 0) {
          elementList.clear();
          counts = new int[26];
        }
      }
    }
    List<Character> elementsAsChars = new ArrayList<Character>();
    for (Integer integer : elementList) {
      elementsAsChars.add((char)('A' + integer));
    }
    return elementsAsChars.toString();
  }
}
