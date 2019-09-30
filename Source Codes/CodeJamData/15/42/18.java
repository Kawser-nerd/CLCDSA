import java.util.Arrays;
import java.util.Scanner;

public class B {
    static double EPS = 1e-9;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            double V = sc.nextDouble();
            double X = sc.nextDouble();
            Source[] sources = new Source[N];
            for (int i = 0; i < N; i++) {
                sources[i] = new Source(sc.nextDouble(), sc.nextDouble());
            }
            Arrays.sort(sources);
            if (X < sources[0].temp || X > sources[N - 1].temp) {
                System.out.println("Case #" + caseNum + ": IMPOSSIBLE");
                continue;
            }
            double[] usage = new double[N];
            for (int i = 0; i < N; i++) {
                usage[i] = 1;
            }
            double initialTemp = computeTemp(sources, usage);
            if (Math.abs(initialTemp - X) < EPS) {
                double totalRate = computeTotalRate(N, sources, usage);
                System.out.println("Case #" + caseNum + ": " + (V / totalRate));
            } else if (initialTemp < X) {
                for (int i = 0; i < N; i++) {
                    usage[i] = 0;
                    double nextTemp = computeTemp(sources, usage);
                    if (nextTemp >= X) {
                        double otherRate = computeTotalRate(N, sources, usage);
                        usage[i] = otherRate * (X - nextTemp) / (sources[i].temp - X) / sources[i].rate;
                        break;
                    }
                }
                double totalRate = computeTotalRate(N, sources, usage);
                System.out.println("Case #" + caseNum + ": " + (V / totalRate));
            } else {
                for (int i = N - 1; i >= 0; i--) {
                    usage[i] = 0;
                    double nextTemp = computeTemp(sources, usage);
                    if (nextTemp <= X) {
                        double otherRate = computeTotalRate(N, sources, usage);
                        usage[i] = otherRate * (X - nextTemp) / (sources[i].temp - X) / sources[i].rate;
                        break;
                    }
                }
                double totalRate = computeTotalRate(N, sources, usage);
                System.out.println("Case #" + caseNum + ": " + (V / totalRate));
            }

        }
    }

    private static double computeTotalRate(int N, Source[] sources, double[] usage) {
        double totalRate = 0;
        for (int i = 0; i < N; i++) {
            totalRate += usage[i] * sources[i].rate;
        }
        return totalRate;
    }

    static double computeTemp(Source[] sources, double[] usage) {
        double tv = 0, v = 0;
        for (int i = 0; i < sources.length; i++) {
            Source source = sources[i];
            tv += source.rate * source.temp * usage[i];
            v += source.rate * usage[i];
        }
        return tv / v;
    }

    private static class Source implements Comparable<Source> {
        double rate;
        double temp;

        public Source(double rate, double temp) {
            this.rate = rate;
            this.temp = temp;
        }

        @Override
        public int compareTo(Source o) {
            return Double.compare(temp, o.temp);
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            long temp;
            temp = Double.doubleToLongBits(rate);
            result = prime * result + (int) (temp ^ (temp >>> 32));
            temp = Double.doubleToLongBits(this.temp);
            result = prime * result + (int) (temp ^ (temp >>> 32));
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            Source other = (Source) obj;
            if (Double.doubleToLongBits(rate) != Double.doubleToLongBits(other.rate)) {
                return false;
            }
            if (Double.doubleToLongBits(temp) != Double.doubleToLongBits(other.temp)) {
                return false;
            }
            return true;
        }
    }
}
