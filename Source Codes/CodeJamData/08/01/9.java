import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Hashtable;
import java.util.Scanner;


public class Saving {
	public void solve(Scanner in, PrintStream out) throws Exception {
		int numTests = in.nextInt();
		for (int t = 1; t <= numTests; t++) {
			int numEngines = in.nextInt();
			Hashtable<String, Integer> table = new Hashtable<String, Integer>();
			in.nextLine();
			for (int e = 0; e < numEngines; e++) {
				table.put(in.nextLine(), e);
			}
			
			//get queries						
			int numQueries = in.nextInt();
			int[] query = new int[numQueries];
			//System.out.println("Queries: " + numQueries);
			in.nextLine();
			for (int q = 0; q < numQueries; q++) {
				String a = in.nextLine();				
				query[q] = table.get(a);
				//System.out.println(a + ", " + query[q]);
			}
			
			//Process it			
			int numSwitches = 0;
			int curEngine = -1;
			//Current query processing
			for (int curQ = 0; curQ < numQueries; curQ++) {
				//If you don't need to change the engine or its the first query
				//move on
				if (curEngine != query[curQ] && curEngine != -1) {
					continue;
				}
				
				//Search for an engine to switch such that it maximizes the time you don't need to switch
				
				//Go through all the engines
				int bestScore = 0;	//How long you don't need to switch engines
				int bestEngine = 0;	//currently the best engine
				for (int e = 0; e < numEngines; e++) {
					//Go through until you repeat
					int curBest = 0;
					for (int q = curQ; q < numQueries; q++) {
						if (query[q] == e) {
							break;
						}
						curBest++;
					}				
					if (curBest > bestScore) {
						bestScore = curBest;
						bestEngine = e;
					}
					
				}
				curEngine = bestEngine;
				numSwitches++;
				
			}
			//The first switch doesn't count
			numSwitches--;
			if (numSwitches <0) {
				numSwitches = 0;
			}
			out.println("Case #" + t + ": " + numSwitches);
			
			
			
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = null;
		PrintStream out = null;
		in = new Scanner(System.in);
		out = System.out;
		in = new Scanner(new FileReader("A-large.in"));
		out = new PrintStream(new FileOutputStream("A-large.out"));
		new Saving().solve(in, out);
		out.close();
		System.exit(0);
	}
}
