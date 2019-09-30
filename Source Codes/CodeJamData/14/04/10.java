package con2014Q;

import java.io.*;
import java.util.*;

public class D {
	
	private static final String islarge = "-large";
	private static final String fileName = "results/con2014Q/"+D.class.getSimpleName().toLowerCase()+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	

	private void solve() {
		int N = in.nextInt();
		double[] Naomi = new double[N],
				Ken = new double[N];
		for (int i = 0; i < N; i++) {
			Naomi[i] = Double.parseDouble(in.next());
		}
		for (int i = 0; i < N; i++) {
			Ken[i] = Double.parseDouble(in.next());
		}
		Arrays.sort(Naomi);
		Arrays.sort(Ken);
		out.println(scoreDecWar(Naomi, Ken)+" "+scoreWar(Naomi, Ken));
	}
	
	static int scoreWar(double[]n, double[]k){
		int score = 0;
		LinkedList<Double> listN = new LinkedList<Double>(),
			listK = new LinkedList<Double>();
		for(int i=0;i<n.length;i++)listN.add(n[i]);
		for(int i=0;i<k.length;i++)listK.add(k[i]);
		while(!listN.isEmpty()){
			double d = listN.pollLast(), d2 = -1;
			Iterator<Double> it = listK.iterator();
			while(it.hasNext()){
				d2 = it.next();
				if(d2>d){
					it.remove();
					break;
				}
			}
			if(d2<d)score++;
		}
		return score;
	}
	

	static int scoreDecWar(double[]n, double[]k){
		LinkedList<Double> listN = new LinkedList<Double>(),
			listK = new LinkedList<Double>();
		int score = 0;
		for(int i=0;i<n.length;i++)listN.add(n[i]);
		for(int i=0;i<k.length;i++)listK.add(k[i]);
		while(!listN.isEmpty()){
			Iterator<Double> it = listN.iterator();
			boolean rem = false;
			while(it.hasNext()){
				if(it.next() > listK.peekFirst()){
					rem=true;
					it.remove();
					score++;
					break;
				}
			}
			if(rem){
				listK.pollFirst();
			}else{
				listN.pollFirst();
				listK.pollLast();
			}
		}
		return score;
	}
	
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new D().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
