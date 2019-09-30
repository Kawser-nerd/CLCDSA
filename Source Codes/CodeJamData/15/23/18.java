import java.io.FileInputStream;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Tifuera
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int[] D = new int[N];
        int[] H = new int[N];
        int[] M = new int[N];
        int hSum = 0;
        List<Dear> dears = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            D[i] = in.nextInt();
            H[i] = in.nextInt();
            M[i] = in.nextInt();

            hSum += H[i];
            for (int j = 0; j < H[i]; j++) {
                dears.add(new Dear(D[i], M[i] + j));
            }
        }

//        if (hSum < 2) {
//            out.println("Case #" + testNumber + ": " + 0);
//            return;
//        }

//        Dear faster = dears.get(0);
//        Dear slower = dears.get(1);
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < dears.size(); i++) {
            int cur = 0;
            for (int j = 0; j < dears.size(); j++) {
                cur += timesMet(dears.get(i), dears.get(j));
            }
            res = Math.min(res, cur);
        }
//        if (faster.minutes == slower.minutes) {
//            out.println("Case #" + testNumber + ": " + 0);
//            return;
//        } else if (faster.minutes > slower.minutes) {
//            Dear temp = faster;
//            faster = slower;
//            slower = temp;
//        }
//
//        double slowerFinishTime = (1d - slower.start / 360d) * slower.minutes;
//        double fasterFinishTime = (1d - faster.start / 360d) * faster.minutes;
//        if (slowerFinishTime <= fasterFinishTime) {
//            out.println("Case #" + testNumber + ": " + 0);
//            return;
//        }
//        if (faster.minutes + fasterFinishTime <= slowerFinishTime) {
//            out.println("Case #" + testNumber + ": " + 1);
//            return;
//        }
        out.println("Case #" + testNumber + ": " + res);
    }

    private int timesMet(Dear first, Dear second) {
        if (first.minutes == second.minutes) {
            return 0;
        }

        double firstFinishTime = (1d - first.start / 360d) * first.minutes;
        double secondFinishTime = (1d - second.start / 360d) * second.minutes;
        if (firstFinishTime < secondFinishTime) {
            return 1;
        }
        double tmp = (firstFinishTime - secondFinishTime) / second.minutes;
        return (int) tmp;
//        if(first.start >= second.start){
//            return (int) tmp;
//        }else{
//            return (int) (tmp+1);
//        }
    }

    private static class Dear {
        int start;
        int minutes;

        public Dear(int start, int speed) {
            this.start = start;
            this.minutes = speed;
        }
    }


}

class InputReader {
    private BufferedReader reader;
    private String[] currentArray;
    private int curPointer;

    public InputReader(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }


    public String next() {
        try {
            currentArray = null;
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() {
        if ((currentArray == null) || (curPointer >= currentArray.length)) {
            try {
                currentArray = reader.readLine().split(" ");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            curPointer = 0;
        }
        return Integer.parseInt(currentArray[curPointer++]);
    }

}

