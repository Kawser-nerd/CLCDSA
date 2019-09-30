import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();
    int Q = sc.nextInt();
    int array[] = new int[N];
    for (int i = 0; i < N; i++) {
      array[i] = sc.nextInt();
    }
    solve(N, K, Q, array);
  }

  private static void solve(int N, int K, int Q, int array[]) {
    List<Integer> list = new ArrayList<>();
    List<Integer> bigList = new ArrayList<>();
    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < N; i++) {
      int selected = array[i]; // smallest
      for (int j = 0; j < N; j++) {
        if (array[j] >= selected) {
          list.add(array[j]);
        } else {
          addToBigList(list, bigList, K);
        }
      }
      addToBigList(list, bigList, K);
      if (bigList.size() >= Q) {
        bigList.sort(Integer::compare);
        int qthSmallest = bigList.get(Q-1);
        int tmp = qthSmallest - selected;
        if (tmp < ans) {
          ans = tmp;
        }
      }
      bigList.clear();
    }
    System.out.println(ans);
  }
  
  private static void addToBigList(List<Integer> list, List<Integer> bigList, int K) {
    if (list.size() >=  K) {
      list.sort(Integer::compare);
      bigList.addAll(list.subList(0, list.size()-K+1));
    }
    list.clear();
  }
}