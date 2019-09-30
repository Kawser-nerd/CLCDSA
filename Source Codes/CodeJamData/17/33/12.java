import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;


public class C {

	static boolean verb=true;
	static void log(Object X){if (verb) System.err.println(X);}
	static void log(Object[] X){if (verb) {for (Object U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(int[] X){if (verb) {for (int U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(long[] X){if (verb) {for (long U:X) System.err.print(U+" ");System.err.println("");}}
	static void logWln(Object X){if (verb) System.err.print(X);}
	static void info(Object o){	System.out.println(o);}
	static void output(Object o){outputWln(""+o+"\n");	}
	static void outputWln(Object o){try {out.write(""+ o);} catch (Exception e) {}}


	static boolean allocate(double[] p,double u,double target){
		// can we allocate additional values to p such that minimum is target ??
		double sum=0;
		for (int i=0;i<p.length;i++){
			if (p[i]<target)
				sum+=target-p[i];
		}
		return sum<=u;
	}
	
	static double margin=0.00000000001;
	
	static double solveSmall(double[] p,double u,int n,int k){
		double lo=0;
		double hi=1;
		while (hi-lo>margin){
			double mid=(lo+hi)/2;
			if (allocate(p,u,mid)){
				lo=mid;
			} else {
				hi=mid;
			}
		}
		double target=(lo+hi)/2;
		double res=1;
		for (int i=0;i<n;i++){
			if (p[i]<target)
				res*=target;
			else
				res*=p[i];
		}
		return res;
	}
	
	
	
	
	// Global vars
	static BufferedWriter out;

	static void process() throws Exception {
		Locale.setDefault(Locale.US);


		File inputFile=new File("C.in");
		PrintWriter outputFile= new PrintWriter("C.out","UTF-8");
		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);


		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			
			int n=sc.nextInt();
			int k=sc.nextInt();
			double u=sc.nextDouble();
			double[] p=new double[n];
			double s=0;
			for (int i=0;i<n;i++)  {
				p[i]=sc.nextDouble();
				s+=p[i];
			}
			String ss=""+solveSmall(p,u,n,k);

			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);


		}



		sc.close();
		outputFile.close();


	}



	public static void main(String[] args) throws Exception {


		process();


	}






}
