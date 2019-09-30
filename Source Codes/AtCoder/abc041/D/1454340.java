import java.util.Scanner;

public class Main {

    private static Scanner scan = new Scanner(System.in);
    private static long[] result;

    public static void main(String[] args) {
	int N = Integer.parseInt(scan.next());
	int M = Integer.parseInt(scan.next());
	boolean[][] link = new boolean[N][N];
	for (int i = 0; i < M; i++) {
	    int x = Integer.parseInt(scan.next()) - 1;
	    int y = Integer.parseInt(scan.next()) - 1;
	    link[x][y] = true;
	}

	int total = pow(2, N);
	result = new long[total];
	for (int i = 0; i < total; i++) {
	    result[i] = count(i, link);
	}

	System.out.println(result[total-1]);
	scan.close();
    }

    private static int pow(int x, int y) {
	if(y == 0) return 1;

	int x2 = pow(x, y/2);
	int result = x2 * x2;
	if(y%2 != 0) result = result * x;
	return result;
    }

    private static String convert(int x) {
	return String.format("%16s", Integer.toBinaryString(x)).replace(" ", "0");
    }

    private static boolean contains(int s, int i) {
	String str = convert(s);
	return str.charAt(str.length()-1-i) == '1';
    }

    private static boolean hasLink(int v, int s, boolean[][] link) {
	boolean result = false;
	for (int i = 0; i < link[0].length; i++) {
	    if(link[v][i] && contains(s, i)) {
		result = true;
		break;
	    }
	}
	return result;
    }

    private static long count(int s, boolean[][] link) {
	if(result[s] > 0) return result[s];
	if(s == 0) return 1;

	long result = 0;
	String str = convert(s);
	for (int i = 0; i < link[0].length; i++) {
	    if(str.charAt(str.length()-1-i) == '1' && !hasLink(i, s, link)) {
		    StringBuilder s2 = new StringBuilder(str);
		    s2.setCharAt(str.length()-1-i, '0');
		    result += count(Integer.parseInt(s2.toString(), 2), link);
	    }
	}
	return result;
    }
}