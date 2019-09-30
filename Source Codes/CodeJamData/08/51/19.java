import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.*;

/**
 *
 */
public class A {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner("c:/projekty/gcj/input.txt");

            FileOutputStream out = new FileOutputStream("c:/projekty/gcj/output.txt");

            int numberOfCases;
            numberOfCases = scanner.nextInt();

            PrintWriter wr = new PrintWriter(out);
            for (int i = 0; i < numberOfCases; i++) {
                doCase(i + 1, scanner, wr);
            }
            wr.close();
            out.close();

        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }


    static class Point {
        int x, y;

        public Point() {

        }


        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Line {
        Point p1;
        Point p2;
    }

    static Map<Integer, List<Line>> verticalLines;
    static Map<Integer, List<Line>> horizontalLines;

    private static void doCase(int caseNumber, Scanner sc, PrintWriter wr) throws IOException {

        int l = sc.nextInt();


//        enum dir {
//            LEFT,
//        }
        verticalLines = new HashMap<Integer, List<Line>>();
        horizontalLines = new HashMap<Integer, List<Line>>();
//
        int direction = 0;      // 0 - up, 1 - right, 2 - bottom, 3 - left
        Point p = new Point();
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
        for (int i = 0; i < l; i++) {
            String s = sc.nextString();
            int times = sc.nextInt();

            for (int k = 0; k < times; k++) {
            for (int j = 0; j < s.length(); j++) {
                if (p.x < minX) {
                    minX = p.x;
                }
                if (p.y < minY) {
                    minY = p.y;
                }
                if (p.x > maxX) {
                    maxX = p.x;
                }
                if (p.y > maxY) {
                    maxY = p.y;
                }

                switch (s.charAt(j)) {
                    case 'F':
                        Point pp;
                        if (direction == 0) {
                            pp = new Point(p.x, p.y + 1);
                        } else if (direction == 1) {
                            pp = new Point(p.x + 1, p.y);
                        } else if (direction == 2) {
                            pp = new Point(p.x, p.y - 1);
                        } else /*if (direction == 3) */{
                            pp = new Point(p.x - 1, p.y);
                        }
                        addLine(p, pp);
                        p = pp;
                        break;
                    case 'L':
                        direction = (direction + 4 - 1) % 4;
                        break;
                    case 'R':
                        direction = (direction + 1) % 4;
                        break;
                }
                if (p.x < minX) {
                    minX = p.x;
                }
                if (p.y < minY) {
                    minY = p.y;
                }
                if (p.x > maxX) {
                    maxX = p.x;
                }
                if (p.y > maxY) {
                    maxY = p.y;
                }
            }
            
            }
        }

        int surface = 0;
        for (int x = minX - 1; x <= maxX + 1; x++) {
            for (int y = minY - 1; y <= maxY + 1; y++) {
                if (!isInside(x, y)) {
                    if (isHorizontalPocket(x, y) || isVerticalPocket(x, y)) {
                        surface++;
                    }
                }
            }
        }

        wr.println("Case #" + caseNumber + ": " + surface);
        System.out.println("Case #" + caseNumber + ": " + surface);
    }

    private static boolean isHorizontalPocket(int x, int y) {
        List<Line> line = verticalLines.get(y);
        if (line == null) return false;

        boolean smaller = false, larger = false;
        for (Line l : line) {
            if (l.p1.x <= x) {
                smaller = true;
                if (larger) {
                    return true;
                }
            } else {
                larger = true;
                if (smaller) {
                    return true;
                }
            }
        }

        return smaller && larger;

    }

    private static boolean isVerticalPocket(int x, int y) {
        List<Line> line = horizontalLines.get(x);
        if (line == null) return false;

        boolean smaller = false, larger = false;
        for (Line l : line) {
            if (l.p1.y <= y) {
                smaller = true;
                if (larger) {
                    return true;
                }
            } else {
                larger = true;
                if (smaller) {
                    return true;
                }
            }
        }

        return smaller && larger;

    }

    private static boolean isInside(int x, int y) {
        List<Line> line = verticalLines.get(y);
        if (line == null) return false;

        int cnt = 0;
        for (Line l : line) {
            if (l.p1.x <= x) {
                cnt++;
            }
        }

        return (cnt & 1) != 0;

    }


    private static void addLine(Point p, Point pp) {
        Line l = new Line();
        l.p1 = p;
        l.p2 = pp;

        if (p.y == pp.y) {
            // horizontal
            int xx = Math.min(p.x, pp.x);
            List<Line> ll = horizontalLines.get(xx);
            if (ll == null) {
                ll = new LinkedList<Line>();
                horizontalLines.put(xx, ll);
            }

            ll.add(l);

        } else {
            int yy = Math.min(p.y, pp.y);
            List<Line> ll = verticalLines.get(yy);
            if (ll == null) {
                ll = new LinkedList<Line>();
                verticalLines.put(yy, ll);
            }

            ll.add(l);
        }
    }


}
