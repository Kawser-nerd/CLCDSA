import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            int[] F = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                F[i] = sc.nextInt();
            }

            int[] longestIn = new int[N + 1];
            boolean[] isPair = new boolean[N + 1];
            int numPairs = 0;
            int longestWithPair = 0;
            int longestCycle = 0;

            for (int i = 1; i <= N; i++) {
                int offsets[] = new int[N + 1];
                int index = i;
                int offset = 1;
                int length = 0;
                while (true) {
                    length++;
                    offsets[index] = offset++;
                    int nextIndex = F[index];
                    if (offsets[nextIndex] != 0) {
                        int cycle = offset - offsets[nextIndex];
                        if (cycle == 2) {
                            longestWithPair = Math.max(longestWithPair, length);
                            if (!(isPair[index] || isPair[nextIndex])) {
                                isPair[index] = isPair[nextIndex] = true;
                                numPairs++;
                            }
                            longestIn[nextIndex] = Math.max(longestIn[nextIndex], length - 2);
                        } else {
                            longestCycle = Math.max(longestCycle, cycle);
                        }
                        break;
                    } else {
                        index = nextIndex;
                    }
                }
            }
            int totalChains = 0;
            for (int i = 1; i <= N; i++) {
                if (F[F[i]] == i && i < F[i]) {
                    totalChains += longestIn[i] + longestIn[F[i]] + 2;
                }
            }
            System.out.println("Case #" + caseNum + ": " + Math.max(longestCycle, totalChains));
        }
    }
}
