import java.io.*;
import java.util.*;

public class probB {

    public static void main(String[] args) throws Exception {
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	int cases = Integer.parseInt(in.readLine());
	for (int i=0; i<cases; i++) {
	    int[] ans = oneCase(in);
	    System.out.println("Case #" + (i+1) + ": " + ans[0] + " " + ans[1]);
	}
    }

    private static int[] oneCase(BufferedReader in) throws Exception {
	int[] result = new int[2];

	int t = Integer.parseInt(in.readLine());
	String l = in.readLine();
	int[] N = parseTwo(l);
	
	int[] aA = new int[N[1]];
	int[] aD = new int[N[0]];
	int[] bA = new int[N[0]];
	int[] bD = new int[N[1]];

	//Unnecessary casework... should have made two two-dim arrays
	for (int i=0; i<N[0]; i++) {
	    int[] sched = parseTwo(in.readLine());
	    aD[i] = sched[0];
	    bA[i] = sched[1]+t;
	}
	for (int i=0; i<N[1]; i++) {
	    int[] sched = parseTwo(in.readLine());
	    bD[i] = sched[0];
	    aA[i] = sched[1]+t;
	}

	Arrays.sort(aA);
	Arrays.sort(aD);
	Arrays.sort(bA);
	Arrays.sort(bD);


	//First, station A
	int trains = 0;
	int maxTrains = 0;
	int a=0;
	int d=0;
	while (a<N[1] || d<N[0]) {
	    if (a == N[1] || (d<N[0] && aA[a] > aD[d])) {
		d++;
		trains++;
		if (trains > maxTrains) maxTrains = trains;
		//System.out.println("Departure: " + aD[d-1]);
	    } else {
		a++;
		trains--;
		//System.out.println("Arrival: " + aA[a-1]);
	    }
	}
	result[0] = maxTrains;

	//Second, station B (code repetition... sad)
	trains = 0;
	maxTrains = 0;
	a=0;
	d=0;
	while (a<N[0] || d<N[1]) {
	    if (a == N[0] || (d<N[1] && bA[a] > bD[d])) {
		d++;
		trains++;
		if (trains > maxTrains) maxTrains = trains;
		//System.out.println("Departure: " + aD[d-1]);
	    } else {
		a++;
		trains--;
		//System.out.println("Arrival: " + aA[a-1]);
	    }
	}
	result[1] = maxTrains;

	return result;
    }
    

    private static int[] parseTwo(String l) {
	int s = l.indexOf(' ');
	String one = l.substring(0,s);
	String two = l.substring(s+1);
	int[] result = new int[2];

	if (one.indexOf(':') < 0) {
	    result[0] = Integer.parseInt(one);
	    result[1] = Integer.parseInt(two);
	} else {
	    int h1 = Integer.parseInt(one.substring(0,2));
	    int h2 = Integer.parseInt(two.substring(0,2));
	    int m1 = Integer.parseInt(one.substring(3));
	    int m2 = Integer.parseInt(two.substring(3));
	    result[0] = 60*h1 + m1;
	    result[1] = 60*h2 + m2;
	}
	return result;

    }

}