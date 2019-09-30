import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

/**
 * Created by jzj on 14/04/2017.
 */
public class ProblemC {
    public static void main(String[] args) throws CloneNotSupportedException {
        Scanner in = new Scanner(System.in);
        int testCount = in.nextInt();
        for (int testNo = 1; testNo <= testCount; testNo++) {
            solve(testNo, in);
        }
    }

    private static class State {
        int hd, ad, hk, ak;

        public State(int hd, int ad, int hk, int ak) {
            this.hd = hd;
            this.ad = ad;
            this.hk = hk;
            this.ak = ak;
        }

        public State(State state) {
            this(state.hd, state.ad, state.hk, state.ak);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (hd != state.hd) return false;
            if (ad != state.ad) return false;
            if (hk != state.hk) return false;
            return ak == state.ak;
        }

        @Override
        public int hashCode() {
            int result = hd;
            result = 31 * result + ad;
            result = 31 * result + hk;
            result = 31 * result + ak;
            return result;
        }

        @Override
        public String toString() {
            return "State{" +
                    "hd=" + hd +
                    ", ad=" + ad +
                    ", hk=" + hk +
                    ", ak=" + ak +
                    '}';
        }
    }

    static Map<State, Integer> map;
    static Queue<State> queue;

    private static void solve(int testNo, Scanner in) throws CloneNotSupportedException {
        int hd = in.nextInt();
        int ad = in.nextInt();
        int hk = in.nextInt();
        int ak = in.nextInt();
        int buff = in.nextInt();
        int debuff = in.nextInt();
        map = new HashMap<>();
        queue = new ArrayDeque<>();
        State init = new State(hd, ad, hk, ak);
        map.put(init, 0);
        queue.add(init);
        int answer = -1;
        while (!queue.isEmpty()) {
            State cur = queue.poll();
//            System.out.println(cur);
            int val = map.get(cur);
            // attack
            State newState = new State(cur);
            newState.hk -= newState.ad;
            if (newState.hk <= 0) {
                answer = val + 1;
                break;
            }
            newState.hd -= newState.ak;
            if (newState.hd > 0) {
                if (!map.containsKey(newState)) {
                    map.put(newState, val + 1);
                    queue.offer(newState);
                }
            }
            // buff
            newState = new State(cur);
            newState.ad += buff;
            newState.ad = Math.min(newState.ad, 200);
            newState.hd -= newState.ak;
            if (newState.hd > 0) {
                if (!map.containsKey(newState)) {
                    map.put(newState, val + 1);
                    queue.offer(newState);
                }
            }
            // cure
            newState = new State(cur);
            newState.hd = init.hd;
            newState.hd -= newState.ak;
            if (newState.hd > 0) {
                if (!map.containsKey(newState)) {
                    map.put(newState, val + 1);
                    queue.offer(newState);
                }
            }
            // debuff
            newState = new State(cur);
            newState.ak -= debuff;
            newState.ak = Math.max(newState.ak, 0);
            newState.hd -= newState.ak;
            if (newState.hd > 0) {
                if (!map.containsKey(newState)) {
                    map.put(newState, val + 1);
                    queue.offer(newState);
                }
            }
        }
        if (answer == -1) {
            System.out.println("Case #" + testNo + ": " + "IMPOSSIBLE");
        } else {
            System.out.println("Case #" + testNo + ": " + answer);
        }
    }

}
