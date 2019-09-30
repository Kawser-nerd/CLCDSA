import java.util.*;
import java.util.stream.Collectors;


public class Main {
    enum Color {
        R("R"),
        B("B"),
        G("G");
        public String name;

        private Color(String string) {
            this.name = string;
        }

        public static Color toEnum(String string) {
            if (string.equals(R.name)) {
                return R;
            } else if (string.equals(B.name)) {
                return B;
            } else {
                return G;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int N = scanner.nextInt();
        final String S = scanner.next();
        Deque<Color> deque = new ArrayDeque<>();
        String[] strings = S.split("");
        for (int i = 0; i < N; i++) {
            Color ball = Color.toEnum(strings[i]);
            if (deque.size() == 0) {
                deque.addLast(ball);
                continue;
            }
            if (deque.size() == 1) {
                Color ball1 = deque.getFirst();
                if (ball1 == ball) {
                    deque.removeFirst();
                } else {
                    deque.addLast(ball);
                }
                continue;
            }
            Color ball1 = deque.getFirst();
            Color ball2 = deque.getLast();
            if (ball == ball1) {
                deque.removeFirst();
                continue;
            }
            if (ball == ball2) {
                deque.removeLast();
                continue;
            }
            //?????????????
            if (i == N - 1) {
                deque.addLast(ball);
                continue;
            }
            Color nextBall = Color.toEnum(strings[i + 1]);
            if (ball == nextBall) {
                deque.addLast(ball);
                continue;
            }
            if (ball1 == nextBall) {
                deque.addLast(ball);
            } else if (ball2 == nextBall) {
                deque.addFirst(ball);
            }
        }
        System.out.println(deque.size());

    }

}