import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.util.HashSet;

public class Main {
	public static HashSet<String> exist;
	public static HashSet<String> need;

	public static void main(String[] args) {
		try {
			File file = new File("A-large.in");
			FileInputStream fis = new FileInputStream(file);
			BufferedInputStream bis = new BufferedInputStream(fis);
			BufferedReader dis = new BufferedReader(new InputStreamReader(bis));

			File ofile = new File("A-large.out");
			if (!ofile.exists()) {
				ofile.createNewFile();
			}
			PrintStream out = new PrintStream(new FileOutputStream(ofile));

			int T = Integer.parseInt(dis.readLine());
			int c = 0;

			while (c++ < T) {
				String next = dis.readLine();
				String[] arr = next.split(" ");
				int N = Integer.parseInt(arr[0]);
				int K = Integer.parseInt(arr[1]);

				exist = new HashSet<String>();
				need = new HashSet<String>();

				for (int i = 0; i < N; i++) {
					put(dis.readLine(),exist);
				}
				for (int i = 0; i < K; i++) {
					put(dis.readLine(),need);
				}

				out.print("Case #" + c + ": ");
				need.removeAll(exist);
				out.println(need.size());

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

	public static void put(String in, HashSet h) {
		String[] split = in.split("/");
		String a = "";
		for (int i = 1; i < split.length; i++) {
			a += split[i];
			h.add(a);
		}
	}
}
