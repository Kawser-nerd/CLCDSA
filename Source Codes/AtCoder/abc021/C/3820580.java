import java.io.PrintWriter;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        Task task = new Task();
        task.solve(sc, out);
        out.flush();
        sc.close();
    }

    static class Task {
        public void solve(Scanner sc, PrintWriter out) {
            int n = nint(sc);
            int a = nint(sc);
            int b = nint(sc);
            int m = nint(sc);
            int[] xList = new int[m];
            int[] yList = new int[m];
            for (int i = 0; i < m; i++) {
                xList[i] = nint(sc);
                yList[i] = nint(sc);
            }

            List<Map<Integer, Integer>> routeMap = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                Map<Integer, Integer> tmp = new HashMap<>();
                routeMap.add(tmp);
            }
            for (int i = 0; i < m; i++) {
                int x = xList[i];
                int y = yList[i];
                Map<Integer, Integer> tmp1 = routeMap.get(x-1);
                tmp1.put(y - 1, 1);
                routeMap.set(x - 1, tmp1);
                Map<Integer, Integer> tmp2 = routeMap.get(y-1);
                tmp2.put(x - 1, 1);
                routeMap.set(y - 1, tmp2);

            }
            Dijkstra dijkstra = new Dijkstra(routeMap, a-1, b-1);
            int[] result = dijkstra.execute();
            out.println(dijkstra.getRouteCount());
           
        }
    }

    private static class Dijkstra {
        private int startPoint;
        private int goalPoint;
        private List<Map<Integer, Integer>> routeMap;
        private int[] routeCount;
        private int[] prev;


        Dijkstra(List<Map<Integer, Integer>> routeMap, int startPoint) {
            this.startPoint = startPoint;
            this.routeMap = routeMap;
            this.goalPoint = -1;

        }

        Dijkstra(List<Map<Integer, Integer>> routeMap, int startPoint, int goalPoint) {
            this.startPoint = startPoint;
            this.routeMap = routeMap;
            this.goalPoint = goalPoint;

        }

        private int getRouteCount() {
            return this.routeCount[this.goalPoint];
        }

        public List<Integer> getPath(){
            List<Integer> path = new ArrayList<>();
            int dest = this.goalPoint;
            path.add(this.goalPoint);
            while (this.prev[dest] != Integer.MAX_VALUE){
                path.add(prev[dest]);
                dest = prev[dest];
            }
            Collections.reverse(path);
            return path;
        }

        public int[] execute() {
            int numberOfCity = this.routeMap.size();
            int[] dist = new int[numberOfCity];
            this.prev = new int[numberOfCity];
            this.routeCount = new int[numberOfCity];
            for (int i = 0; i < numberOfCity; i++) {
                dist[i] = Integer.MAX_VALUE;
                this.prev[i] = Integer.MAX_VALUE;
                this.routeCount[i] = 0;
            }
            dist[this.startPoint] = 0;
            this.routeCount[this.startPoint] = 1;
            PriorityQueue<Node> pQueue = new PriorityQueue<>();
            pQueue.offer(new Node(this.startPoint, 0));
            while (!pQueue.isEmpty()) {
                Node node = pQueue.poll();
                int prev_cost = node.getCost();
                int src = node.getNode();
                if (dist[src] < prev_cost) {
                    continue;
                }
                for (Map.Entry<Integer, Integer> e : this.routeMap.get(src).entrySet()) {
                    int dest = e.getKey();
                    int cost = e.getValue();

                    if (cost != Integer.MAX_VALUE && dist[dest] > dist[src] + cost) {
                        dist[dest] = dist[src] + cost;
                        this.prev[dest] = src;
                        pQueue.offer(new Node(dest, dist[dest]));
                    }

                    if (dist[dest] == dist[src] + cost) {
                        this.routeCount[dest] += this.routeCount[src];
                        this.routeCount[dest] %=  1000000007;
                    }

                }
            }

            return dist;

        }

    }

    private static class Node implements Comparable<Node> {
        private int node;
        private int cost;

        public Node(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node node2) {
            return Integer.compare(this.cost, node2.cost);
        }

        public int getNode() {
            return this.node;
        }

        public int getCost() {
            return this.cost;
        }
    }


    static int nint(Scanner sc) {


        return Integer.parseInt(sc.next());
    }

    static long nlong(Scanner sc) {
        return Long.parseLong(sc.next());
    }

    static double ndouble(Scanner sc) {
        return Double.parseDouble(sc.next());
    }

    static float nfloat(Scanner sc) {
        return Float.parseFloat(sc.next());
    }

    static String nstr(Scanner sc) {
        return sc.next();
    }

    static long[] longLine(Scanner sc, int size) {
        long[] lLine = new long[size];
        for (int i = 0; i < size; i++) {
            lLine[i] = nlong(sc);
        }
        return lLine;
    }

    static int[] intLine(Scanner sc, int size) {
        int[] iLine = new int[size];
        for (int i = 0; i < size; i++) {
            iLine[i] = nint(sc);
        }
        return iLine;
    }

    static String[] strLine(Scanner sc, int size) {
        String[] strLine = new String[size];
        for (int i = 0; i < size; i++) {
            strLine[i] = nstr(sc);
        }
        return strLine;
    }

    static long maxFromList(List<Long> longList) {
        return longList.stream().max(Comparator.naturalOrder()).get();
    }

    static long minFromList(List<Long> longList) {
        return longList.stream().min(Comparator.naturalOrder()).get();
    }

    public static int sumDigits(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static long sumDigits(long n) {
        long sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    static List<Integer> getIntegerList(Scanner sc, int size) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(nint(sc));
        }
        return list;
    }

    static List<Long> getLongList(Scanner sc, int size) {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(nlong(sc));
        }
        return list;
    }

    static List<String> getStringList(Scanner sc, int size) {
        List<String> stringList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            stringList.add(nstr(sc));
        }
        return stringList;
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static Map<Integer, Integer> primeFactorize(long num) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 2;
        while (i * i <= num) {
            while (num % i == 0) {
                num /= i;
                if (map.containsKey(i)) {
                    int tmp = map.get(i);
                    tmp++;
                    map.put(i, tmp);
                } else {
                    map.put(i, 1);
                }
            }
            i++;
        }
        if (num > 1)
            map.put((int) num, 1);
        return map;
    }

    /**
     * Returns the most frequent value in the list. ????????????????
     *
     * @param list List
     * @return most frequent value
     */
    private static Integer getMode(List<Integer> list) {
        if (list.size() <= 0) {
            throw new IllegalArgumentException();
        }

        Map<Integer, Integer> modeMap = new HashMap<>();

        for (Integer x : list) {
            if (modeMap.containsKey(x)) {
                modeMap.put(x, modeMap.get(x) + 1);
            } else {
                modeMap.put(x, 1);
            }
        }
        return modeMap.entrySet().stream().max(Map.Entry.comparingByValue()).get().getKey();

    }
}