using System;

class D {
    class Graph {
        public int[,] A;

        public Graph(int n) {
            A = new int[n, n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    A[i, j] = int.MaxValue >> 1;
        }

        public Graph(Graph g) { A = g.A.Clone() as int[,]; }

        public void AddEdge(int s, int t, int c) {
            A[s, t] = A[t, s] = c;
        }

        public void Floyd() {
            for (int i = 0; i < A.GetLength(0); ++i)
                for (int j = 0; j < A.GetLength(0); ++j)
                    for (int k = 0; k < A.GetLength(0); ++k) {
                        var newA = A[j, i] + A[i, k];
                        if (newA < A[j, k]) A[j, k] = newA;
                    }
        }
    }

    public static void Main() {
        var line = Console.ReadLine().Split();
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var graph = new Graph(n);
        for (int i = 0; i < m; ++i) {
            line = Console.ReadLine().Split();
            var a = int.Parse(line[0]) - 1;
            var b = int.Parse(line[1]) - 1;
            var c = int.Parse(line[2]);
            graph.AddEdge(a, b, c);
        }
        var graph1 = new Graph(graph);
        graph.Floyd();
        var answer = 0L;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (graph1.A[i, j] != int.MaxValue >> 1)
                    if (graph.A[i, j] < graph1.A[i, j]) ++answer;
        Console.WriteLine(answer >> 1);
    }
}