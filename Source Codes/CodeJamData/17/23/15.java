import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Pony {
	public static void main(String[] args) throws IOException{
		BufferedReader buf = new BufferedReader(new FileReader("Pony.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Pony.out")));
		int t = Integer.parseInt(buf.readLine());
		for(int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			String[] s = buf.readLine().split(" ");
			int n = Integer.parseInt(s[0]);
			int q = Integer.parseInt(s[1]);
			int[][] input = new int[n][2];
			double[][] edges1 = new double[n][n];
			for(int j = 0; j < n; j++){
				s = buf.readLine().split(" ");
				input[j][0] = Integer.parseInt(s[0]);
				input[j][1] = Integer.parseInt(s[1]);
			}
			for(int j = 0; j < n; j++){
				s = buf.readLine().split(" ");
				for(int k = 0; k < n; k++){
					if(Integer.parseInt(s[k]) == -1){
						edges1[j][k] = Double.POSITIVE_INFINITY;
					}
					else edges1[j][k] = Double.parseDouble(s[k]);
				}
			}
			double[][] paths1 = floydWarshall(edges1, n);
			double[][] edges2 = new double[n][n];
			for(int j = 0; j < n; j++) {
				double max = input[j][0] + 0.1;
				double speed = input[j][1];
				for(int k = 0; k < n; k++){
					if(paths1[j][k] <= max){
						edges2[j][k] = paths1[j][k]/speed;
					} else {
						edges2[j][k] = Double.POSITIVE_INFINITY;
					}
				}
			}
			double[][] paths2 = floydWarshall(edges2, n);
			for(int j = 0; j < q; j++){
				s = buf.readLine().split(" ");
				int start = Integer.parseInt(s[0]) - 1;
				int end = Integer.parseInt(s[1]) - 1;
				out.print(paths2[start][end] + " ");
			}
			out.println();
		}
		out.close();
	}
	//below code taken from http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
	//slightly modified
	public static double[][] floydWarshall(double graph[][], int n)
    {
        double dist[][] = new double[n][n];
        int i, j, k;
 
        /* Initialize the solution matrix same as input graph matrix.
           Or we can say the initial values of shortest distances
           are based on shortest paths considering no intermediate
           vertex. */
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                dist[i][j] = graph[i][j];
 
        /* Add all vertices one by one to the set of intermediate
           vertices.
          ---> Before start of a iteration, we have shortest
               distances between all pairs of vertices such that
               the shortest distances consider only the vertices in
               set {0, 1, 2, .. k-1} as intermediate vertices.
          ----> After the end of a iteration, vertex no. k is added
                to the set of intermediate vertices and the set
                becomes {0, 1, 2, .. k} */
        for (k = 0; k < n; k++)
        {
            // Pick all vertices as source one by one
            for (i = 0; i < n; i++)
            {
                // Pick all vertices as destination for the
                // above picked source
                for (j = 0; j < n; j++)
                {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of dist[i][j]
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
 
        // Print the shortest distance matrix
        return dist;
    }
}
