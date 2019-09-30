import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;

public class A implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "";
	static String outputFile = "";
	
	static {
		inputFile = A.class.getName() + ".in";
		outputFile = A.class.getName() + ".out";
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}
	
	public long lread() throws Exception {
		return Long.parseLong(readword());
	}
	
	public String readword() throws Exception {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) {
			c = in.read();
		}
		if( c < 0 ) return "";
		StringBuilder bld = new StringBuilder();
		while( c > ' ' ) {
			bld.append((char)c);
			if( c == ')') break;
			c = in.read();
		}
		return bld.toString();
	}
	
	public class Node {
		double w;
		String s;
		Node left, right;
	}
	
	Node root;
	HashSet<String> props;
	
	public void parse( Node curNode ) throws Exception {
		int c = 0;
		while( c <= ' ' ) {
			c = in.read();
		}
		if( c == '(' ) {
			String s = readword();
			if( s.charAt(s.length()-1) == ')') {
				curNode.w = Double.parseDouble(s.substring(0,s.length()-1));
				return;
			}
			curNode.w = Double.parseDouble(s);
			c = in.read();
			while( c <= ' ' ) {
				c = in.read();
			}
			if(c == ')') {
				return;
			}
			StringBuilder bld = new StringBuilder();
			while( c > ' ' ) {
				bld.append((char)c);
				c = in.read();
			}
			curNode.s = bld.toString();
			curNode.left = new Node();
			curNode.right = new Node();
			parse( curNode.left );
			parse( curNode.right );
			c = ' ';
			while( c != ')') c = in.read();
		}
	}
	
	public double calc( Node curNode) {
		if( curNode.s == null) return curNode.w;
		if( props.contains(curNode.s )) return curNode.w * calc(curNode.left); else
			return curNode.w * calc(curNode.right);
	}
	
	public void solve() throws Exception {
		readword();
		root = new Node();
		parse(root);
		int n = Integer.parseInt(readword());
		for( int t = 0; t < n; t++) {
			readword();
			int m = Integer.parseInt(readword());
			props = new HashSet<String>();	
			for( int i = 0; i < m; i++) {
				props.add(readword());
			}
			DecimalFormat df = new DecimalFormat("0.00000000");
			out.write( df.format(calc(root)) + "\n");
		}
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader( inputFile ));
			out = new BufferedWriter( new FileWriter( outputFile ));
//			in = new BufferedReader( new InputStreamReader(System.in));
//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			int n = iread();
			for( int i = 0; i < n; i++) {
				out.write("Case #" + (i+1) + ":\n");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread( new A()).start();
	}

}
