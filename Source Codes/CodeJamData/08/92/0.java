import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class ProblemBHard {
	public long cnt(long W, long H, long stx, long sty, long dx, long dy) {
		long l = 0, r = 10000000;
		while (r-l>1) {
			long c=(l+r)/2;
			if (stx+c*dx >= 0 && stx+c*dx < W &&
				sty+c*dy >= 0 && sty+c*dy < H)
				l = c;
			else
				r = c;
		}
		return l + 1;
	}

	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum<=caseCnt; caseNum++) {
			System.out.println(caseNum);
			pw.print("Case #" + caseNum + ": ");
			long W = sc.nextInt(), H = sc.nextInt();
			long dx1 = sc.nextInt(), dy1 = sc.nextInt();
			long dx2 = sc.nextInt(), dy2 = sc.nextInt();
			long stx = sc.nextInt(), sty = sc.nextInt();
			boolean same = false;
			for (long a=-100; a<=100; a++)
				for (long b=-100; b<=100; b++)
					if (a*a+b*b>0 && a*dx1==b*dx2 && a*dy1==b*dy2) {
						same=true;
						break;
					}
			if (same) {
				boolean[] used = new boolean[1000000];
				int[] qx = new int[2000000], qy = new int[2000000];
				int qBeg=0, qEnd=0;
				qx[qBeg] = (int)stx; qy[qBeg++] = (int)sty;
				used[(dy1==0?(int)stx:(int)sty)]=true;
				while (qEnd < qBeg) {
					int curx = qx[qEnd], cury = qy[qEnd++];
					if (curx+dx1>=0 && curx+dx1<W && cury+dy1>=0 && cury+dy1<H
						&& !used[dy1==0?(int)(curx+dx1):(int)(cury+dy1)]) {
						qx[qBeg] = (int)(curx+dx1);
						qy[qBeg++] = (int)(cury+dy1);
						used[dy1==0?(int)(curx+dx1):(int)(cury+dy1)] = true;
					}
					if (curx+dx2>=0 && curx+dx2<W && cury+dy2>=0 && cury+dy2<H
						&& !used[dy2==0?(int)(curx+dx2):(int)(cury+dy2)]) {
						qx[qBeg] = (int)(curx+dx2);
						qy[qBeg++] = (int)(cury+dy2);
						used[dy2==0?(int)(curx+dx2):(int)(cury+dy2)] = true;
					}
				}
				pw.println(qBeg);
			} else {
				long res = 0;
				while (true) {
					res += cnt(W, H, stx, sty, dx1, dy1);
					boolean ok = true;
					while (stx+dx2 < 0 || stx+dx2 >= W ||
						   sty+dy2 < 0 || sty+dy2 >= H) {
						stx += dx1;
						sty += dy1;
						if (stx < 0 || stx >= W || sty < 0 || sty >= H) {
							ok = false;
							break;
						}
					}
					if (!ok) break;
					stx += dx2;
					sty += dy2;
				}
				pw.println(res);
			}
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemBHard()).doMain();
	}}
