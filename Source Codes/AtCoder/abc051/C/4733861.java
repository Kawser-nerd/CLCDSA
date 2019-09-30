import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int sx = sc.nextInt();
	int sy = sc.nextInt();
	int tx = sc.nextInt();
	int ty = sc.nextInt();
	StringBuilder sb = new StringBuilder();
	int w = Math.abs(sx-tx);
	int h = Math.abs(sy-ty);
	for ( int i = 0; i < h; i++ ) {
	    sb.append("U");
	}
	for ( int i = 0; i < w+1; i++ ) {
	    sb.append("R");
	}
	for ( int i = 0; i < h+1; i++ ) {
	    sb.append("D");
	}
	for ( int i = 0; i < w+1; i++ ) {
	    sb.append("L");
	}
	sb.append("U");

	//2
	sb.append("L");
	for ( int i = 0; i < h+1; i++ ) {
	    sb.append("U");
	}
	for ( int i = 0; i < w+1; i++ ) {
	    sb.append("R");
	}
	for ( int i = 0; i < h+1; i++ ) {
	    sb.append("D");
	}
	for ( int i = 0; i < w; i++ ) {
	    sb.append("L");
	}
	String str = sb.toString();
	System.out.println(str);
    }
}