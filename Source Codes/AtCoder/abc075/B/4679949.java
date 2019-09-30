import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int H = sc.nextInt();
	int W = sc.nextInt();
	char[][] a = new char[H+2][W+2];
	for(int i = 1; i<H+1; i++) {
	    String str = sc.next();
	    for(int j = 1; j<W+1; j++) {
		a[i][j] = str.charAt(j-1);
	    }
	}
	for(int i = 1; i<H+1; i++) {
	    for(int j = 1; j<W+1; j++) {
		if(a[i][j]=='.') {
		    System.out.print(((int)((a[i-1][j]=='#')?1:0) + (int)((a[i-1][j-1]=='#')?1:0) + (int)((a[i-1][j+1]=='#')?1:0)
				     + (int)((a[i][j]=='#')?1:0) + (int)((a[i][j-1]=='#')?1:0) + (int)((a[i][j+1]=='#')?1:0)
				      + (int)((a[i+1][j]=='#')?1:0) + (int)((a[i+1][j-1]=='#')?1:0) + (int)((a[i+1][j+1]=='#')?1:0)));
		}else {
		    System.out.print('#');
		}
	    }
	    System.out.println();
	}

    }
}