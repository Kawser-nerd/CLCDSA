import java.util.*;
import java.io.*;

public class SnapperChain
{
    private static String solve(Scanner scanner)
    {
	int N = scanner.nextInt();
	int K = scanner.nextInt();
	int mask = 1 << (N);
	mask--;
	return (K & mask) == mask ? "ON"
	    : "OFF";
    }

    public static void main(String[] argv)
    {
	Scanner scanner = new Scanner(System.in);
	int N = scanner.nextInt();
	scanner.nextLine();
	for (int i = 1; i <= N; i++)
	    {
		System.out.printf("Case #%d: %s%n", i, solve(scanner));
	    }
    }
}