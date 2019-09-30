import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int sx = sc.nextInt();
		int sy = sc.nextInt();
		int tx = sc.nextInt();
		int ty = sc.nextInt();
		char[] vChars = new char[ty - sy];
		char[] hChars = new char[tx - sx];
		Arrays.fill(hChars, 'L');
		String left = new String(hChars);
		Arrays.fill(hChars, 'R');
		String right = new String(hChars);
		Arrays.fill(vChars, 'D');
		String down = new String(vChars);
		Arrays.fill(vChars, 'U');
		String up = new String(vChars);
		
		StringBuilder sb = new StringBuilder();
		sb.append(up).append(right);
		sb.append('U').append(left).append('L').append(down).append('D').append('R');
		sb.append(right).append(up);
		sb.append('R').append(down).append('D').append(left).append('L').append('U');
		System.out.println(sb);
	}
}