import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] bodies = new String[sc.nextInt()];
        int[] voted = new int[bodies.length];
        String temp;
        int lastElement = 0;
        flag:
        for (int i = 0; i < bodies.length; i++) {
            temp = sc.next();
            try {
                for (int j = 0; j < bodies.length; j++) {
                    if (bodies[j].equals(temp)) {
                        voted[j]++;
                        continue flag;
                    }
                }
            } catch (NullPointerException e) {
                bodies[lastElement] = temp;
                voted[lastElement]++;
                lastElement++;
            }

        }
        int mostVoted = 0;
        int mostVotedBody = 0;
        for (int i = 0; i < voted.length; i++) {
            if (voted[i] > mostVoted) {
                mostVoted = voted[i];
                mostVotedBody = i;
            }
        }
        System.out.println(bodies[mostVotedBody]);

    }

}