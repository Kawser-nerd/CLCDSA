import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Edge> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            edges.add(new Edge(sc.nextInt() - 1,
                    sc.nextInt() - 1, sc.nextInt()));
        }
        edges.sort((o1, o2) -> Integer.valueOf(o2.year).compareTo(o1.year));
        int q = sc.nextInt();
        PriorityQueue<Person> persons = new PriorityQueue<>(
                (o1, o2) -> Integer.valueOf(o2.year).compareTo(o1.year));
        int[] anss = new int[q];
        for (int i = 0; i < q; i++) {
            int v = sc.nextInt() - 1;
            int w = sc.nextInt();
            persons.add(new Person(v, w, i));
        }

        UnionFind uf = new UnionFind(n);
        Person person = persons.poll();
        for (Edge edge : edges) {
            while (edge.year <= person.year) {
                if (!persons.isEmpty()) {
                    anss[person.index] = uf.count(person.city);
                    person = persons.poll();
                }
                else {
                    if (anss[person.index] == 0) {
                        anss[person.index] = uf.count(person.city);
                    }
                    break;
                }
            }
            uf.unite(edge.origin, edge.destination);
        }
        if (anss[person.index] == 0) {
            persons.add(person);
        }
        while (!persons.isEmpty()) {
            Person p = persons.poll();
            anss[p.index] = uf.count(p.city);
        }

        for (int i = 0; i < q; i++) {
            System.out.println(anss[i]);
        }
    }

    static class Edge {
        int origin;
        int destination;
        int year;

        public Edge(int origin, int destination, int year) {
            this.origin = origin;
            this.destination = destination;
            this.year = year;
        }
    }

    static class Person {
        int city;
        int year;
        int index;

        public Person(int city, int year, int index) {
            this.city = city;
            this.year = year;
            this.index = index;
        }
    }

    // Implement size of each tree as well as union and find
    static class UnionFind {
        int[] parent;
        // only roots have correct counts
        int[] count;

        public UnionFind(int size) {
            parent = new int[size];
            count = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                count[i] = 1;
            }
        }

        // return the root of the input
        // adopt path compression
        public int find(int a) {
            if (parent[a] == a) return a;
            parent[a] = find(parent[a]);
            return parent[a];
        }

        // adopt weighted union rule
        public void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (count[a] < count[b]) {
                parent[a] = b;
                count[b] += count[a];
            } else {
                parent[b] = a;
                count[a] += count[b];
            }
        }

        public boolean differ(int a, int b) {
            a = find(a);
            b = find(b);
            return a != b;
        }

        public int count(int a) {
            return count[find(a)];
        }
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}