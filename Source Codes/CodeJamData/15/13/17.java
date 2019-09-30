import java.util.Locale;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.FilenameFilter;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
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
			outputStream = new FileOutputStream("c.txt");
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
        out.println("Case #" + testNumber + ":");
        int countPoints = in.nextInt();
        Point[] points = new Point[countPoints];
        for (int i = 0; i < countPoints; ++i) {
            int x = in.nextInt(), y = in.nextInt();
            points[i] = new Point(x, y);
            points[i].id = i;
        }
        int[] res = new int[countPoints];
        Arrays.fill(res, countPoints-1);
        for (int o = 0; o < countPoints; ++o) {
            Point[] p = new Point[countPoints - 1];
            int cnt = 0;
            int n = countPoints - 1;
            for (int i = 0; i < countPoints; ++i) {
                if (i != o) {
                    p[cnt++] = points[i].sub(points[o]);
                }
            }

            Arrays.sort(p, new Comparator<Point>() {
                public int compare(Point p1, Point p2) {
                    return DoubleUtils.compareTo(p1.angle(), p2.angle());
                }
            });

            int ptr = 0;
            int am = 0;
            List<Double> angles = new ArrayList<Double>();
            for (int i = 0; i < n; ++i) {
                angles.add(p[i].angle());
                angles.add(p[i].angle() + Math.PI + Math.PI);
            }

            Collections.sort(angles, new Comparator<Double>() {
                public int compare(Double a, Double b) {
                    return DoubleUtils.compareTo(a, b);
                }
            });
            List<Double> aa = new ArrayList<Double>();
            if (angles.size() == 0) {
                res[o] = 0;
                continue;
            }
            aa.add(angles.get(0));
            for (int i = 1; i < angles.size(); ++i) {
                if (DoubleUtils.compareTo(aa.get(aa.size()-1), angles.get(i)) != 0) {
                    aa.add(angles.get(i));
                }
            }
            angles = aa;
            TreeSet<Double> has = new TreeSet<Double>(new Comparator<Double>() {
                public int compare(Double a, Double b) {
                    return DoubleUtils.compareTo(a, b);
                }
            });
            int total = 0;
            for (Double anAa : aa) {
                has.add(anAa);
                if (DoubleUtils.compareTo(anAa, Math.PI) <= 0) {
                    ++total;
                }
            }
            for (int i = 0; i < aa.size(); ++i) {
                if (DoubleUtils.compareTo(angles.get(i), Math.PI) > 0) break;
                int left = i + 1, right = aa.size()-1;
                int middle, r = -1;
                double need = angles.get(i) + Math.PI;
                while (left <= right) {
                    middle = (left + right) / 2;
                    if (DoubleUtils.compareTo(angles.get(middle), need) < 0) {
                        r = middle;
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
                if (r != -1) {
                    res[o] = Math.min(res[o], r - i);
                    int other = total-1;
                    if (has.contains(need)) {
                        --other;
                    }
                    res[o] = Math.min(res[o], other);
                } else {
                    res[o] = 0;
                }
            }
        }

//        for (int i = 0; i < countPoints; ++i) {
//            for (int j = 0; j < countPoints; ++j) {
//                if (i != j) {
//                    Point V = points[j].sub(points[i]);
//                    int sideA = 0;
//                    int sideB = 0;
//                    for (int k = 0; k < countPoints; ++k) {
//                        if (k != i && k != j) {
//                            Point U = points[k].sub(points[i]);
//                            if (V.crossProductSign(U) > 0) {
//                                ++sideA;
//                            } else if (V.crossProductSign(U) < 0) {
//                                ++sideB;
//                            }
//                        }
//                    }
//                    res[i] = Math.min(res[i], sideA);
//                    res[i] = Math.min(res[i], sideB);
////                    res[j] = Math.min(res[j], sideA);
////                    res[j] = Math.min(res[j], sideB);
//                }
//            }
//        }
        for (int i = 0; i < countPoints; ++i) {
            out.println(res[i]);
        }
    }

//    class Point {
//        long x, y;
//        int id;
//
//        public Point(long x, long y) {
//            this.x = x;
//            this.y = y;
//        }
//
//        public void setId(int id) {
//            this.id = id;
//        }
//
//        public Point sub(Point p) {
//            return new Point(p.x - x, p.y - y);
//        }
//
//        public int crossProductSign(Point V) {
//            return Long.signum(crossProduct(V));
//        }
//
//        public long crossProduct(Point V) {
//            return x * V.y - y * V.x;
//        }
//    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }
}

class Point implements Comparable<Point> {
    public double x, y;
    public int id;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "(" + x + ", " + y + " )";
    }

    public boolean equals(Object o) {
        Point p = (Point) o;
        return DoubleUtils.compareTo(x, p.x) == 0 && DoubleUtils.compareTo(y, p.y) == 0;
    }

    public int hashCode() {
        int result;
        long temp;
        temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
        result = (int) (temp ^ (temp >>> 32));
        temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
        result = 31 * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    public Point sub(Point p) {
        return new Point(x - p.x, y - p.y);
    }

    /*public double distanceToLine(Line l) {
        if (l.hasPoints()) {
            return distanceToLine(l.p1, l.p2);
        }
        Line normLine = l.norm();
        return normLine.a * x + normLine.b * y + normLine.c;
    } */

    public double angle() {
        return Math.atan2(y, x);
    }

    public int compareTo(Point o) {
        int temp = DoubleUtils.compareTo(x, o.x);
        if (temp == 0) {
            return DoubleUtils.compareTo(y, o.y);
        }
        return temp;
    }
}

class DoubleUtils {
    public static final double EPS = 1e-10;

    public static int compareTo(double a, double b) {
        if (doubleEqual(a, b)) {
            return 0;
        }
        if (a < b) {
            return -1;
        }
        return 1;
    }

    private static boolean doubleEqual(double a, double b) {
        return Math.abs(a - b) < EPS;
    }

}

