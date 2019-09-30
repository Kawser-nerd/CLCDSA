//package a;

import java.util.*;
import java.io.*;

public class Main implements Runnable {

	public Scanner in;

	public PrintWriter out;

	Main() throws IOException {
		in = new Scanner( new File( "in" ) );
		out = new PrintWriter( new File( "out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void check( boolean f, String msg ) {
		if ( ! f ) {
			out.close();
			throw new RuntimeException( msg );
		}
	}

	public void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int old = in.nextInt();
            int create = in.nextInt();
            in.nextLine();
            Node root = new Node();
            for ( int i = 0; i < old; i ++ ) {
                add( root, in.nextLine().split("/"), 1 );
            }
            int r = 0;
            for ( int i = 0; i < create; i ++ ) {
                r += add( root, in.nextLine().split("/"), 1 );
            }
			out.println( "Case #" + test + ": " + r );
		}
		try {
			close();
		} catch ( IOException e ) {
			e.printStackTrace();
		}
	}

    int add( Node node, String[] tokens, int p ) {
        if ( p >= tokens.length ) {
            return 0;
        }
        //System.out.println( tokens[p] );
        int r = 0;
        if ( node.children.get( tokens[p] ) == null ) {
            node.children.put( tokens[p], new Node() );
            r = 1;
        }
        return r + add( node.children.get( tokens[p] ), tokens, p + 1 );
    }

    public class Node {
        Map< String, Node > children;

        Node() {
            children = new TreeMap<String, Node>();
        }
    }

	public static void main( String[] args ) throws IOException {
		new Thread( new Main() ).start();
	}
}
