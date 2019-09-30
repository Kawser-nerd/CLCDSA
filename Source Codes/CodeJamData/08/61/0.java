import java.io.*;
import java.util.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = sc.nextInt();
		mainbit: for (int t=1; t<=T; t++) {
			System.out.println("Case #"+t+":");
			int N = sc.nextInt();
			int[][] bird = new int[N][2];
			int[][] input;
			boolean isbird = false;
			boolean[] yup = new boolean[N];
			int minx=100000000, miny=minx;
			int maxx=-100000000, maxy=maxx;
			for (int i=0; i<N; i++) {
				bird[i][0] = sc.nextInt();
				bird[i][1]=sc.nextInt();
				String next = sc.next();
				if (next.equals("BIRD")) {
					isbird=true;
					minx = Math.min(minx,bird[i][0]);
					maxx = Math.max(maxx,bird[i][0]);
					miny = Math.min(miny,bird[i][1]);
					maxy = Math.max(maxy,bird[i][1]);
					yup[i]=true;
				} else {
					sc.next();
					yup[i]=false;
				}
			}

			int M = sc.nextInt();
			input = new int[M][2];

			for (int i=0; i<M; i++) {input[i][0]=sc.nextInt();input[i][1]=sc.nextInt();}
			if (!isbird) {
				hehe: for (int i=0; i<M; i++) {
					for (int j=0; j<N; j++) {
						if (input[i][0]==bird[j][0] && input[i][1]==bird[j][1]) {
							System.out.println("NOT BIRD");
							continue hehe;
						}
					}
					System.out.println("UNKNOWN");

				}
				continue mainbit;
			}
			loop: for (int i=0; i<M; i++) {
				if (input[i][0]>=minx && input[i][1]>=miny && input[i][0]<=maxx && input[i][1]<=maxy) {
					System.out.println("BIRD");
				} else {
					int badminx, badminy, badmaxx, badmaxy;
					if (input[i][0]>=maxx && input[i][1]>=maxy) {
						badminx=minx;
						badmaxx=input[i][0];
						badminy=miny;
						badmaxy=input[i][1];
					} else if (input[i][0]>=maxx && input[i][1]>=miny) {
						badminx=maxx;
						badmaxx=input[i][0];
						badminy=miny;
						badmaxy=maxy;
					} else if (input[i][0]>=maxx) {
						badminx=minx;
						badmaxx=input[i][0];
						badminy=input[i][1];
						badmaxy=maxy;
					} else if (input[i][0]>=minx && input[i][1]>=maxy) {
						badminx=minx;
						badmaxx=maxx;
						badminy=maxy;
						badmaxy=input[i][1];
					} else if (input[i][0]>=minx) {
						badminx=minx;
						badmaxx=maxx;
						badminy=input[i][1];
						badmaxy=miny;
					} else if (input[i][1]>=maxy) {
						badminx=input[i][0];
						badmaxx=maxx;
						badminy=miny;
						badmaxy=input[i][1];
					} else if (input[i][1]>=miny) {
						badminx=input[i][0];
						badmaxx=minx;
						badminy=miny;
						badmaxy=maxy;
					} else {
						badminx=input[i][0];
						badmaxx=maxx;
						badminy=input[i][1];
						badmaxy=maxy;
					}

					for (int j=0; j<N; j++) {
						if (yup[j]) continue;

						if (bird[j][0]>=badminx && bird[j][0]<=badmaxx && bird[j][1]>=badminy && bird[j][1]<=badmaxy) {
							System.out.println("NOT BIRD");
							continue loop;
						}
					}
					System.out.println("UNKNOWN");

				}
			}

		}
	}
}