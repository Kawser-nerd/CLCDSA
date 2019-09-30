import java.io.*;

public class probA {

    public static void main(String[] args) throws Exception {
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	int cases = Integer.parseInt(in.readLine());
	for (int i=0; i<cases; i++) {
	    int ans = switches(in);
	    System.out.println("Case #" + (i+1) + ": " + ans);
	}
    }

    private static int switches(BufferedReader in) throws Exception {
	int numE = Integer.parseInt(in.readLine());
	String[] engines = new String[numE];
	for (int i=0; i<numE; i++) {
	    engines[i] = in.readLine();
	}
	int numQ = Integer.parseInt(in.readLine());
	String[] queries = new String[numQ];
	for (int i=0; i<numQ; i++) {
	    queries[i] = in.readLine();
	}

	//Tracks switches needed if ending on a specified engine at certain step.
	
	int[][] a = new int[numQ][numE];

	if (numQ == 0) return 0;

	for (int i=0; i<numE; i++) {
	    a[0][i] = (queries[0].equals(engines[i]))? numQ : 0;
	}

	String s = "0: ";
	for (int i=0; i<numE; i++) s += a[0][i] + " ";
	//System.out.println(s);

	for (int q = 1; q<numQ; q++) {
	    for (int e=0; e<numE; e++) {
		
		int n = numQ;
		if (engines[e].equals(queries[q])) {
		    a[q][e] = numQ;
		} else {
		    for (int f=0; f<numE; f++) {
			int m = ((f == e)? a[q-1][f] : (a[q-1][f]+1));
			if (m<n) n = m;
		    }
		    a[q][e] = n;
		}
		
	    }
	    s = "" + q + ": ";
	    for (int i=0; i<numE; i++) s += a[q][i] + " ";
	    //System.out.println(s);
	}

	int min = numQ;
	for (int e=0; e<numE; e++) {
	    if (a[numQ-1][e] < min) min = a[numQ-1][e]; 
	}
	return min;
    }
    

}