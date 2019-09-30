import java.util.Arrays;
import java.util.Scanner;

public class Main {

    int N, M, Q;
    int[] par, rank, size, ans;
    Road[] roads;
    Person[] people;

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        par = new int[N];
        rank = new int[N];
        size = new int[N];
        init();
        M = sc.nextInt();
        roads = new Road[M + 1];
        for (int i = 0; i < M; i++) {
            roads[i] = new Road(sc.nextInt() - 1, sc.nextInt() - 1, sc.nextInt());
        }
        roads[M] = new Road(0, 0, -1);
        int Q = sc.nextInt();
        ans = new int[Q];
        people = new Person[Q + 1];
        for (int i = 0; i < Q; i++) {
            people[i] = new Person(sc.nextInt() - 1, sc.nextInt(), i);
        }
        people[Q] = new Person(0, -1, 0);
        Arrays.sort(roads, (o1, o2) -> o2.y - o1.y);
        Arrays.sort(people, (o1, o2) -> o2.w - o1.w);

        int currentRoad = 0;
        int currentPerson = 0;
        while (people[currentPerson].w != -1) {
            if (roads[currentRoad].y > people[currentPerson].w) {
                unite(roads[currentRoad].a, roads[currentRoad].b);
                currentRoad++;
            } else {
                ans[people[currentPerson].num] = size[find(people[currentPerson].v)];
                currentPerson++;
            }
        }
        for (int i = 0; i < Q; i++) {
            System.out.println(ans[i]);
        }
    }

    void init() {
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = find(par[x]);
            return par[x];
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            size[y] += size[x];
            par[x] = y;
        } else {
            size[x] += size[y];
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    class Person {

        int v;
        int w;
        int num;

        Person(int v, int w, int num) {
            this.v = v;
            this.w = w;
            this.num = num;
        }
    }

    class Road {

        int a;
        int b;
        int y;

        Road(int a, int b, int y) {
            this.a = a;
            this.b = b;
            this.y = y;
        }
    }
}