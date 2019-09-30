import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        List<State> stateList = new LinkedList<>();
        State firstState = new State();
        stateList.add(firstState);
        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();

            List<State> newStateList = new LinkedList<>();
            for (State state : stateList) {
                State stateA = new State(state);
                stateA.cost += (stateA.a == 0) ? 0 : 10;
                stateA.a += l;
                newStateList.add(stateA);

                State stateB = new State(state);
                stateB.cost += (stateB.b == 0) ? 0 : 10;
                stateB.b += l;
                newStateList.add(stateB);

                State stateC = new State(state);
                stateC.cost += (stateC.c == 0) ? 0 : 10;
                stateC.c += l;
                newStateList.add(stateC);

                newStateList.add(state);
            }
            stateList = newStateList;
        }

        int ans = Integer.MAX_VALUE;
        for (State s : stateList) {
            ans = Math.min(ans, s.requiredMP(a, b, c));
        }
        System.out.println(ans);
    }
}

class State {
    int a;
    int b;
    int c;
    int cost;

    State() {
        this.a = 0;
        this.b = 0;
        this.c = 0;
        this.cost = 0;
    }

    State(State state) {
        this.a = state.a;
        this.b = state.b;
        this.c = state.c;
        this.cost = state.cost;
    }

    int requiredMP(int a, int b, int c) {
        if (this.a == 0 || this.b == 0 || this.c == 0) {
            return Integer.MAX_VALUE;
        }

        int mp = this.cost + Math.abs(this.a - a) + Math.abs(this.b - b) + Math.abs(this.c - c);
        return mp;
    }
}