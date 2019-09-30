import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.FileOutputStream;

public class Main {
	public static void main(String[] args) {
		try {
			File file = new File("C-large.in");
			FileInputStream fis = new FileInputStream(file);
			BufferedInputStream bis = new BufferedInputStream(fis);
			BufferedReader dis = new BufferedReader(new InputStreamReader(bis));

			File ofile = new File("C-large.out");
			if (!ofile.exists()) {
				ofile.createNewFile();
			}
			PrintStream out = new PrintStream(new FileOutputStream(ofile));

			int[][] f = new int[501][501];
			for (int i = 0; i < 501; i++) {
				for (int j = 0; j < 501; j++) {
					if (i == 0) {
						f[i][j] = 1;
					} else {
						for (int k = 1; k <= j; k++) {
							if (k > i)
								break;
							f[i][j] += f[i - k][j];
						}
						f[i][j] %= 100003;
					}
				}
			}
			int[] f2 = new int[501];
			for (int i = 1; i < 501; i++) {
				for (int j = 0; j <= i; j++) {
					f2[i] += f[j][i - j];
					f2[i] %= 100003;
				}
			}

			int T = Integer.parseInt(dis.readLine());
			int c = 0;

			while (c++ < T) {
				out.print("Case #" + c + ": ");
				out.println(f2[Integer.parseInt(dis.readLine()) - 1]);
			}

			fis.close();
			bis.close();
			dis.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
