import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;


public class Util {
	
	public Scanner s;
	public Scanner is;
	
	public String curStr;
	
	public PrintStream out=System.out;
	
	public Util() {
		is=getInputScanner();
	}
	
	BufferedReader br;
	
	public void scanFile(String filename){
		try {
			br=new BufferedReader(new InputStreamReader(new FileInputStream(new File(filename))));
			s=new Scanner(br);
		} catch (FileNotFoundException e) {
			errln("file: '%s' not found.",filename);
		}
	}
	
	public boolean nextLine(){
		try {
			curStr=br.readLine();
			if (curStr==null){
				return false;
			}
			s=new Scanner(curStr);
			return true;
		} catch (IOException e) {
			return false;
		}
	}
	
	public void outputInFile(String file){
		outputInFile(new File(file));
	}
	
	public void outputInFile(File f){
		try {
			out=new PrintStream(f);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * If using file scanning it can be used to hold calculations and wait for input.
	 * Expects exactly one cr&lf.
	 */
	public void waitForInputSignal(){
		try {
			System.in.read();
			System.in.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public boolean expect(String str){
		String n=s.next();
		if (!n.equals(str)){
			errln("Expected '%s' but next() was '%s'",str,n);
			throw new RuntimeException();
		}
		return true;
	}

	public static final double PI=Math.PI;

	public static double c(double x){
		return Math.cos(x);
	}
	
	public static double s(double x){
		return Math.sin(x);
	}
	
	public static double sq(double x){
		return x*x;
	}
	
	public static double sqrt(double x){
		return Math.sqrt(x);
	}
	
	public static double atan(double x){
		return Math.atan(x);
	}
	
	public void showln(String s, Object... args){
		out.println(String.format(s,args));
	}
	
	public void show(String s, Object... args){
		out.print(String.format(s,args));
	}
	
	public void errln(String s, Object... args){
		System.err.println(String.format(s,args));
	}
	
	public void err(String s, Object... args){
		System.err.print(String.format(s,args));
	}
	
	public static Scanner getInputScanner(){
		return new Scanner(System.in);
	}
	
	public static int min(int a,int b){
		return Math.min(a, b);
	}
	
	public static int max(int a,int b){
		return Math.max(a, b);
	}
	
	public static boolean isPrime(long p){
		if (p<=1)
			return false;
		if (p==2)
			return true;
		if ((p&1)==0)
			return false;
		if (p==3)
			return true;
		if (p==5)
			return true;
		if (p==7)
			return true;
		long i=3;
		while(i*i<=p){
			if (p%i==0)
				return false;
			i+=2;
		}
		return true;
	}
	
}
