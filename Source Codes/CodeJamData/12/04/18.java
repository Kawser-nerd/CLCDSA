import static java.lang.Math.*;

import java.io.*;
import java.util.*;

/**
 * @author Chris Dziemborowicz <chris@dziemborowicz.com>
 * @version 2012.0415
 */
public class HallOfMirrors
{
    public static void main(String[] args)
            throws Exception
    {
        // Get input files
        File dir = new File("/Users/Chris/Documents/UniSVN/code-jam/hall-of-mirrors/data");
        File[] inputFiles = dir.listFiles(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name)
            {
                return name.endsWith(".in");
            }
        });

        // Process each input file
        for (File inputFile : inputFiles) {
            System.out.printf("Processing \"%s\"...\n", inputFile.getName());

            String outputPath = inputFile.getPath().replaceAll("\\.in$", ".out");
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputPath));

            Scanner scanner = new Scanner(inputFile);
            System.out.printf("Number of test cases: %s\n", scanner.nextLine());

            int count = 0;
            while (scanner.hasNext()) {
                int h = scanner.nextInt();
                int w = scanner.nextInt();
                int d = scanner.nextInt();
                scanner.nextLine();
                String[] map = new String[h];
                for (int i = 0; i < h; i++) {
                    map[i] = scanner.nextLine();
                }

                String output = String.format("Case #%d: %d\n", ++count, process(h, w, d, map));

                System.out.print(output);
                writer.write(output);
            }

            writer.close();
            System.out.println("Done.\n");
        }

        // Compare to reference files (if any)
        for (File inputFile : inputFiles) {
            System.out.printf("Verifying \"%s\"...\n", inputFile.getName());

            String referencePath = inputFile.getPath().replaceAll("\\.in$", ".ref");
            String outputPath = inputFile.getPath().replaceAll("\\.in$", ".out");

            File referenceFile = new File(referencePath);
            if (referenceFile.exists()) {
                InputStream referenceStream = new FileInputStream(referencePath);
                InputStream outputStream = new FileInputStream(outputPath);

                boolean matched = true;
                int referenceRead, outputRead;
                do {
                    byte[] referenceBuffer = new byte[4096];
                    byte[] outputBuffer = new byte[4096];

                    referenceRead = referenceStream.read(referenceBuffer);
                    outputRead = outputStream.read(outputBuffer);

                    matched = referenceRead == outputRead
                            && Arrays.equals(referenceBuffer, outputBuffer);
                } while (matched && referenceRead != -1);

                if (matched) {
                    System.out.println("Verified.\n");
                } else {
                    System.out.println("*** NOT VERIFIED ***\n");
                }
            } else {
                System.out.println("No reference file found.\n");
            }
        }
    }


    public static int process(int h, int w, int d, String[] map)
    {
        int x = -1, y = -1;
        for (int xx = 0; xx < map.length; xx++) {
            int yy = map[xx].indexOf('X');
            if (yy != -1) {
                x = xx;
                y = yy;
            }
        }

        int count = 0;
        for (int i = -100; i <= 100; i++) {
            for (int j = -100; j <= 100; j++) {
                int gcd = gcd(i, j);
                if (gcd == 1 || (i == 0 && abs(j) == 1) || (j == 0 && abs(i) == 1)) {
                    count += process(map, x, y, i, j, d);
                }
            }
        }
        return count;
    }


    public static int process(String[] map, int sx, int sy, int dx, int dy, int d)
    {
        int x = sx;
        int y = sy;

        int xs = 0;
        int ys = 0;

        int err = abs(dx) - abs(dy);

        while (true) {
            if (err > 0) {
                x += dx > 0 ? 1 : -1;
                xs++;
                err -= 2 * abs(dy);
                if (map[x].charAt(y) == '#') {
                    dx = -dx;
                    x += dx > 0 ? 1 : -1;
                }
            } else if (err < 0) {
                y += dy > 0 ? 1 : -1;
                ys++;
                err += 2 * abs(dx);
                if (map[x].charAt(y) == '#') {
                    dy = -dy;
                    y += dy > 0 ? 1 : -1;
                }
            } else {
                int ox = x;
                x += dx > 0 ? 1 : -1;
                xs++;
                err -= 2 * abs(dy);

                int oy = y;
                y += dy > 0 ? 1 : -1;
                ys++;
                err += 2 * abs(dx);

                if (map[x].charAt(y) == '#') {
                    if (map[ox].charAt(y) != '#' && map[x].charAt(oy) != '#') {
                        return 0;
                    } else if (map[ox].charAt(y) == '#' && map[x].charAt(oy) == '#') {
                        dx = -dx;
                        x += dx > 0 ? 1 : -1;

                        dy = -dy;
                        y += dy > 0 ? 1 : -1;
                    } else if (map[ox].charAt(y) == '#') {
                        dy = -dy;
                        y += dy > 0 ? 1 : -1;
                    } else {
                        dx = -dx;
                        x += dx > 0 ? 1 : -1;
                    }
                }
            }

            if ((dx == 0 || xs % dx == 0) && (dy == 0 || ys % dy == 0)) {
                if (sqrt(xs * xs + ys * ys) > d) {
                    return 0;
                } else if (map[x].charAt(y) == 'X') {
                    return 1;
                }
            }
        }
    }


    public static int gcd(int a, int b)
    {
        if (a == 0 || b == 0) {
            return -1;
        }

        a = abs(a);
        b = abs(b);

        while (a != 0 && b != 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }

        return a == 0 ? b : a;
    }
}