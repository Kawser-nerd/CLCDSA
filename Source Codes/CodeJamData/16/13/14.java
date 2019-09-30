import java.util.*;

public class C {
	private static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {

		int C = in.nextInt();
		for (int thisCase = 1; thisCase <= C; thisCase++) {
			System.out.printf("Case #%d: %d%n", thisCase, largestCircle());
		}
	}


	private static int largestCircle() {
		int N = in.nextInt();
		int bff[] = new int[N];
		for (int i = 0; i < N; i++) {
			bff[i] = in.nextInt()-1;
		}

		int status[] = new int[N];
		int chainLength[] = new int[N];
		//status: -2 = unvisited
		// -1 = reciprocal
		// N -> this node was reached from N 
		for (int i = 0; i < N; i++) {
			status[i] = -2;
			chainLength[i] = 0;
		}

		//do one pass, checking to see if each kid is a reciprocal
		for (int i = 0; i < N; i++) {
			if (bff[bff[i]] == i) {
				status[i] = -1;
			}
		}
		// for (int i : status) {
		// 	System.out.println(i);
		// }

		// then, we look for chains and loops
		int maxLoopSize = 0;
		for (int i = 0; i < N; i++) {
			if (status[i] != -1) {
				int current = bff[i];
				status[i] = i;
				int steps = 1;
				
				boolean done = false;
				while (!done) {
					// System.out.println(i + " " + current);
					if (current == i) {
						// we have encountered a loop of which i is a member.
						if (steps > maxLoopSize) {
							maxLoopSize = steps;
						}
						done = true;
					}
					else if (status[current] == i) {
						// we have encountered a loop of which i is not a member.
						// we can't figure out the loop size easily, so we just quit. This element is useless.
						done = true;
					}
					else if (status[current] == -1) {
						if (steps>chainLength[current]) {
							chainLength[current] = steps;
						}
						done = true;
					}
					else {
						steps++;
						status[current] = i;
						current = bff[current];
					}
				}
			}
		}

		int frankenCircle = 0;
		for (int i = 0; i < N; i++) {
			if (status[i] == -1) {
				frankenCircle+= (chainLength[i] + 1);
			}
		}

		return Math.max(frankenCircle, maxLoopSize);
	}
}