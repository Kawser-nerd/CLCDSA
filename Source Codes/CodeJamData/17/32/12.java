import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;


public class B4 {

	static boolean verb=true;
	static void log(Object X){if (verb) System.err.println(X);}
	static void log(Object[] X){if (verb) {for (Object U:X) System.err.print(U+" ");System.err.println("");}}
	static void log(int[] X){if (verb) {for (int U:X) System.err.print(U+" ");System.err.println("");}}
	static void logWln(Object X){if (verb) System.err.print(X);}
	static void info(Object o){	System.out.println(o);}
	static void output(Object o){outputWln(""+o+"\n");	}
	static void outputWln(Object o){try {out.write(""+ o);} catch (Exception e) {}}



	/*

	  int[][][] num=new int[2][LX][DX+1];
			for (int e=0;e<2;e++)
				for (int ch=0;ch<LX;ch++)
					Arrays.fill(num[e][ch],MX);
			num[0][0][0]=1;
			num[1][0][0]=1;

			for (int u=0;u<LX;u++){
				int[][][] nxt=new int[2][LX][DX+1];
				for (int e=0;e<2;e++)
					for (int ch=0;ch<LX;ch++)
						Arrays.fill(nxt[e][ch],MX);

				for (int e=0;e<2;e++)
					for (int ch=0;ch<LX;ch++)
						for (int tim=0;tim<LX;tim++){
							if (num[e][ch][tim]!=MX){
								// 2 options: continue or change

								// continue
								if (e==0){
									if (tim+1<=DX && time[e][u]==0){
										nxt[e][ch][tim+1]=Math.min(nxt[e][ch][tim+1],num[e][ch][tim]);
									}
								} else {
									if (u+1-tim<=DX && time[e][u]==0){
										nxt[e][ch][tim]=Math.min(nxt[e][ch][tim],num[e][ch][tim]);
									}
								}

								// change
								if (e==0){
									if (u+1-tim<=DX && time[1-e][u]==0){
										nxt[1-e][ch+1][tim+1]=Math.min(nxt[e][ch][tim+1],num[e][ch][tim]);
									}
								} else {
									if (u+1-tim<=DX && time[e][u]==0){
										nxt[e][ch][tim]=Math.min(nxt[e][ch][tim],num[e][ch][tim]);
									}
								}


							}
						}

			}



	 */


	// Global vars
	static BufferedWriter out;

	static int N;


	static int MX=Integer.MAX_VALUE;
	

	//static int LX=6*24;
	//static int DX=6*12;
	
	static int LX=60*24;
	static int DX=60*12;
	
	static void process() throws Exception {
		Locale.setDefault(Locale.US);


		File inputFile=new File("B.in");
		PrintWriter outputFile= new PrintWriter("B.out","UTF-8");
		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);



		int T=sc.nextInt();
		for (int t=1;t<=T;t++){

			int AC=sc.nextInt();
			int AJ=sc.nextInt();
			int[][] time=new int[2][LX];
			for (int i=0;i<AC;i++){
				int st=sc.nextInt();
				int en=sc.nextInt();
				for (int u=st;u<en;u++)
					time[0][u]=1;
			}

			for (int i=0;i<AJ;i++){
				int st=sc.nextInt();
				int en=sc.nextInt();
				for (int u=st;u<en;u++)
					time[1][u]=1;
			}

			int[][][] num=new int[2][2][DX+1];
			for (int f=0;f<2;f++)
			for (int e=0;e<2;e++)
				Arrays.fill(num[f][e],MX);
			for (int e=0;e<2;e++){
				if (time[e][0]==0)
					num[e][e][0]=0;
			}

			for (int u=0;u<LX;u++){
				int[][][] nxt=new int[2][2][DX+1];
				for (int f=0;f<2;f++)
				for (int e=0;e<2;e++)
					Arrays.fill(nxt[f][e],MX);
				for (int f=0;f<2;f++)
				for (int e=0;e<2;e++)
					for (int tim=0;tim<=DX;tim++){
						if (num[f][e][tim]!=MX){
							// 2 options: continue or change

							// we can continue only if our current agenda is free 
							
							// continue
							if (e==0){
								if (tim+1<=DX && time[e][u]==0){
									//log("case 1");
									nxt[f][e][tim+1]=Math.min(nxt[f][e][tim+1],num[f][e][tim]);
								}
							} else {
								if (u+1-tim<=DX && time[e][u]==0){
									//log("case 2");
									nxt[f][e][tim]=Math.min(nxt[f][e][tim],num[f][e][tim]);
								}
							}

							// change
							if (e==0){
								if (u+1-tim<=DX && time[1-e][u]==0){
									//log("case 3");
									nxt[f][1-e][tim]=Math.min(1+num[f][e][tim],nxt[f][1-e][tim]);
								}
							} else {
								if (1+tim<=DX && time[1-e][u]==0){
									//log("case 4");
									nxt[f][1-e][1+tim]=Math.min(1+num[f][e][tim],nxt[f][1-e][1+tim]);
								}
							}
						}
					}
				
				
				num=nxt;
			
			}
			int min=MX;
			for (int f=0;f<2;f++)
				for (int e=0;e<2;e++){
					int x=num[f][e][DX];
					if (x!=MX){
						if (f!=e)
							x++;
					}
					min=Math.min(min, x);
				}
			// 
			// t time
			// is in charge
			// number swap
			// cumulated for first
			// num[person][num changes][cumlated time]



			String ss=""+min;
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
