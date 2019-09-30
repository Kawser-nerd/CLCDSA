import java.io.IOException;

//10:58am hacking a solution for the small set, just in case... shoudn't take long. WIll literally just do the simulation.

public class ProblemC extends CodeJammer {

	public void print(boolean[][] g, int l) {
		for (int i=0; i<l; i++) {
			String s = "";
			for (int j=0; j<l; j++) {
				if (g[i][j]) {
					s += "1";
				} else {
					s += "0";
				}
			}
			System.out.println(s);
		}
	}
	
	@Override
	public void process() throws IOException {
		int r = reader.readInt();
		boolean[][] g = new boolean[101][101];
		for (int i=0; i<101; i++) {
			for (int j=0; j<101; j++) {
				g[i][j] = false;
			}
		}
		for (int n=0; n<r; n++) {
			int[] data = reader.readArray();
			for (int i=data[0]; i<=data[2]; i++) {
				for (int j=data[1]; j<=data[3]; j++) {
					g[i][j] = true;
				}
			}
		}
		
		long alive = 1;
		int turns = 0;
		while (alive > 0) {
			alive = 0;
			for (int s=200; s>=0; s--) {
				for (int i=0; i<=s && i<=100; i++) {
					int j = s-i;
					if (j>= 0 && j<=100) {
						int neighs = 0;
						if (i>0 && g[i-1][j]) neighs++;
						if (j>0 && g[i][j-1]) neighs++;
						if (neighs == 0) g[i][j] = false;
						if (neighs == 2) g[i][j] = true;
						if (g[i][j]) alive++;
						
					}
				}
			}
			turns++;
			//System.out.println();
			//print(g, 10);
		}
		output(turns);
	}

	public static void main(String[] args) {
		ProblemC p = new ProblemC();
		p.run(args);
	}
	
}
