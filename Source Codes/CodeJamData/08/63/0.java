import java.io.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = sc.nextInt();


		for (int t=1; t<=T; t++) {
			System.out.print("Case #"+t+": ");
			int M = sc.nextInt();
			double P = sc.nextDouble();
			int start = sc.nextInt();

			Vector<Cutoff>[] cutoffs = new Vector[M+1];
			for (int i=0;i<cutoffs.length; i++) cutoffs[i] = new Vector<Cutoff>();
			cutoffs[0].add(new Cutoff(0,0));
			cutoffs[0].add(new Cutoff(1000000,1));

			for (int x=1; x<=M; x++) {
			//	System.out.println("-------------");
				// add an extra round
				// for each previous cutoff take the midopint
				for (int i=0; i<cutoffs[x-1].size(); i++)
				for (int j=i+1; j<cutoffs[x-1].size(); j++) {
					Cutoff a = cutoffs[x-1].get(i);
					Cutoff b = cutoffs[x-1].get(j);
					// if we're here we bet the average and go up or down
					double prob = (1-P)*a.prob+P*b.prob;
					cutoffs[x].add(new Cutoff((a.money+b.money)/2,prob));
				}
				cutoffs[x].add(new Cutoff(0,0));
				cutoffs[x].add(new Cutoff(1000000,1));
				Collections.sort(cutoffs[x]);
				double bestprob=0;
				for (int i=1; i<cutoffs[x].size(); i++) {
					Cutoff c = cutoffs[x].get(i);
					if (c.prob<bestprob) {
						cutoffs[x].remove(i);
						i--;
						continue;
					}
					bestprob=c.prob;
				}
				//for (int j=0; j<cutoffs[x].size(); j++) {
				//	Cutoff c = cutoffs[x].get(j);
					//System.out.println(c.money+" "+c.prob);
				//}
			}
			double bestprob=0;
			for (int i=0; i<cutoffs[M].size(); i++) {
				Cutoff c = cutoffs[M].get(i);
				if (c.money<=start+1e-8) bestprob=c.prob;
				//System.out.println((c.money>=start?1:0)+" "+start+" "+c.prob);
			}
			System.out.println(bestprob);

		}
	}
} class Cutoff implements Comparable<Cutoff> {
	double money, prob;
	public Cutoff(double m, double p) {
		money=m;prob=p;
	}
	public int compareTo(Cutoff other) {
		if (money<other.money) return -1;
		if (money==other.money) return 0;
		return 1;
	}
}