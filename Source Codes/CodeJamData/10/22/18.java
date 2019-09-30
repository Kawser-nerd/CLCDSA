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
			File file = new File("B-large.in");
			FileInputStream fis = new FileInputStream(file);
			BufferedInputStream bis = new BufferedInputStream(fis);
			BufferedReader dis = new BufferedReader(new InputStreamReader(bis));

			File ofile = new File("B-large.out");
			if (!ofile.exists()) {
				ofile.createNewFile();
			}
			PrintStream out = new PrintStream(new FileOutputStream(ofile));

			int T = Integer.parseInt(dis.readLine());
			int c = 0;

			while (c++ < T) {
				out.print("Case #" + c + ": ");

				String next = dis.readLine();
				String[] arr = next.split(" ");
				int N = Integer.parseInt(arr[0]);
				int K = Integer.parseInt(arr[1]);
				int B = Integer.parseInt(arr[2]);
				int t = Integer.parseInt(arr[3]);

				String[] arr2 = dis.readLine().split(" ");
				String[] arr3 = dis.readLine().split(" ");
				int[] X = new int[N];
				int[] V = new int[N];
				for (int i = 0; i < N; i++) {
					X[i] = B - Integer.parseInt(arr2[i]);
					V[i] = Integer.parseInt(arr3[i]);
				}

				int b = 0, s = 0;
				for (int i = N - 1; i >= 0; i--) {
					if (t * V[i] < X[i]) {
						b++;
					} else {
						s += b;
						K--;
						if (K == 0) {
							break;
						}
					}
				}
				if (K > 0) {
					out.println("IMPOSSIBLE");
				} else {
					out.println(s);
				}

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
