import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private final int H;
    private final int W;
    private final char[][] image;
    private final char WHITE = '.';
    private final char BLACK = '#';

    public Main() {
	H = Integer.parseInt(scan.next());
	W = Integer.parseInt(scan.next());
	
	image = new char[H][W];
	for (int i = 0; i < H; i++) {
	    String S = scan.next();
	    for (int j = 0; j < W; j++) {
		image[i][j] = S.charAt(j);
	    }
	}

	scan.close();
    }

    public final void answer() {
	char[][] cand = new char[H][W];
	
	for (int i = 0; i < H; i++) {
	    for (int j = 0; j < W; j++) {
		if(image[i][j] == WHITE) {
		    for (int u = i-1; u <= i+1; u++) {
			for (int v = j-1; v <= j+1; v++) {
			    whiten(cand, u, v);
			}
		    }
		}
	    }
	}

	for (int i = 0; i < H; i++) {
	    for (int j = 0; j < W; j++) {
		if(cand[i][j] != WHITE) blacken(cand, i, j);
	    }
	}

	char[][] converted = new char[H][W];
	for (int i = 0; i < H; i++) {
	    for (int j = 0; j < W; j++) {
		if(containsBlack(cand, i, j)) blacken(converted, i, j);
		else whiten(converted, i, j);
	    }
	}

	boolean isImpossible = false;
	for (int i = 0; i < H; i++) {
	    if(isImpossible) break;
	    
	    for (int j = 0; j < W; j++) {
		if(converted[i][j] != image[i][j]) {
		    isImpossible = true;
		    break;
		}
	    }
	}

	if(isImpossible) {
	    System.out.println("impossible");
	} else {
	    StringBuilder str = new StringBuilder();
	    str.append("possible").append('\n');
	    for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
		    str.append(cand[i][j]);
		}
		str.append('\n');
	    }
	    System.out.println(str.toString());
	}
	
    }

    private final boolean isValid(int i, int j) {
	return 0 <= i && i < H && 0 <= j && j < W;
    }

    private final void whiten(char[][] image, int i, int j) {
	if(isValid(i, j)) image[i][j] = WHITE;
    }

    private final void blacken(char[][] image, int i, int j) {
	if(isValid(i, j)) image[i][j] = BLACK;
    }

    private final boolean containsBlack(char[][] image, int i, int j) {
	boolean result = false;
	for (int u = i-1; u <= i+1; u++) {
	    if(result == true) break;
	    
	    for (int v = j-1; v <= j+1; v++) {
		if(isValid(u, v) && image[u][v] == BLACK) {
		    result = true;
		    break;
		}
	    }
	}

	return result;
    }
}