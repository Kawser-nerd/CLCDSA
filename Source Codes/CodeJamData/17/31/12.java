import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;




public class A {

	static boolean verb=true;
	static void log(Object X){if (verb) System.err.println(X);}
	static void log(Object[] X){if (verb) {for (Object U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(int[] X){if (verb) {for (int U:X) System.err.print(U+" ");System.err.println("");}}
	static void logWln(Object X){if (verb) System.err.print(X);}
	static void info(Object o){	System.out.println(o);}
	static void output(Object o){outputWln(""+o+"\n");	}
	static void outputWln(Object o){try {out.write(""+ o);} catch (Exception e) {}}




	// Global vars
	static BufferedWriter out;
	static class Composite implements Comparable<Composite>{
		int r;
		int h;

		public int compareTo(Composite X){
			if (r!=X.r)
				return X.r-r;
			return X.h-h;
		}

		public Composite(int r, int h) {
			this.r = r;
			this.h = h;
		}


		public String toString(){
			return "("+r+" "+h+")";
		}
		
	}




	static void process() throws Exception {
		Locale.setDefault(Locale.US);

		File inputFile=new File("A.in");
		PrintWriter outputFile= new PrintWriter("A.out","UTF-8");
		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);


		//test();
		double pi=Math.PI;

		int T=sc.nextInt();



		for (int t=1;t<=T;t++){

			int n=sc.nextInt();
			int k=sc.nextInt();
			int[] r=new int[n];
			int[] h=new int[n];
			Composite[] ar=new Composite[n];
			for (int i=0;i<n;i++){
				r[i]=sc.nextInt();
				h[i]=sc.nextInt();
				ar[i]=new Composite(r[i],h[i]);
			}
			Arrays.sort(ar);
			//log(ar);
			double bst=0;
			double[] bob=new double[k+1];
			for (int i=0;i<n;i++){
				double[] nxt=new double[k+1];
				System.arraycopy(bob,0,nxt,0,k+1);
				for (int j=0;j<k;j++){
					double surf=pi;
					surf*=ar[i].r;
					surf*=ar[i].r;
					double slide=2*pi;
					slide*=ar[i].h;
					slide*=ar[i].r;
					double val=0;
					if (j==0)
						val=surf+slide;
					else
						val=bob[j]+slide;
					//log("val:"+val);
					nxt[j+1]=Math.max(nxt[j+1],val);

				}
				bob=nxt;
			}


			String ss=""+bob[k];



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
